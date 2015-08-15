#!/home/rakeshmistry/bin/Python-3.4.3/bin/python3

# @author: rakesh mistry - 'inspire'
# @date: 2015-06-14

import sys
import re
import os
import math
import random
import functools
import collections
import numpy

################################################################################
# Functions to generate SMT2 expressions
def extractExpr(m, n, var):
    return "((_ extract " + str(m) + " " + str(n) + ") " + str(var) + ")"

def xorExpr(var1, var2):
    return "(xor " + str(var1) + " " + str(var2) + ")"

def zeroExtendExpr(bitWidth, varName):
    return "((_ zero_extend " + str(bitWidth) + ") " + varName + ")"

def bvmulExpr(var1, var2):
    return "(bvmul " + str(var1) + " " + str(var2) + ")"

def bvaddExpr(var1, var2):
    return "(bvadd " + str(var1) + " " + str(var2) + ")"

def eqExpr(var1, var2):
    return "(= " + str(var1) + " " + str(var2) + ")"

def constExpr(num, bitWidth):
    return "(_ bv" + str(num) + " " + str(bitWidth) + ")"

def andExpr(var1, var2):
    return "(and " + str(var1) + " " + str(var2) + ")"

################################################################################


# Function: populatePrimesMap
# @param: primesMap - file containing primes.
#         Each line is of the form -- k prime
#         where for every number 'k' the value of 'prime' is smallest prime > 2^k
#
# returns map of prime numbers for 2^k (1 <= k <= 100)
def populatePrimesMap(primesFile):
    primesMap = {}
    for line in primesFile:
        strList = line.split()
        k = int(strList[0])
        primesMap[k] = int(strList[1])

    return primesMap


# Function: populatePrimesMap
# @param: primesMap - file containing primes.
#         Each line is of the form -- k prime
#         where for every number 'k' the value of 'prime' is smallest prime > 2^k
#
# returns map of prime numbers for 2^k (1 <= k <= 100)
def populateEpsilonMap(probFile):
    epsilonMap = {}
    for line in probFile:
        strList = line.rstrip().split(":")
        k = int(strList[0])
        epsilonMap[k] = float(strList[1])

    return epsilonMap


# Function: computeNewBitwidth
def computeNewBitwidth(k, slices, varMap):
    totalBitwidth = 0
    for key in varMap.keys():
        totalBitwidth += math.ceil(float(varMap[key]) / k)
    
    newBitwidth = k + int(math.ceil(math.log(slices * totalBitwidth, 2))) + 1 # +1 since 's' can be upto 'prime-1'

    return newBitwidth


# Function: generateEquationConstraint
# @param: varmap - a map of variables with key as variable name and value being
#         its width
# @param: maxBitwidth - maximum bitwidth
# @param: slices - number of slices for each variable to create
#
# Generates an equation of the form:
#     a1x1 + a2x2 + ... = s*prime + r
def generateEquationConstraint(varMap, primesMap, maxBitwidth, slices):
    generateEquationConstraint.counter += 1

    k = int(math.ceil(float(maxBitwidth) / slices))

    twoPowerK = 2 ** k
    prime = primesMap[k]

    newBitwidth = computeNewBitwidth(k, slices, varMap)

    primeCoeff = "temp_prime_coeff_" + str(generateEquationConstraint.counter)
    primeCoeffDecl = "(declare-fun " + primeCoeff + " () (_ BitVec " + str(newBitwidth - (k + 1)) + "))\n"

    bvmulList = []
    for key in varMap.keys():
        originalKey = key
        if varMap[key] != maxBitwidth:
            key = zeroExtendExpr(maxBitwidth - varMap[key], key)

        assert maxBitwidth >= slices

        # find slice widths of variable
        keyDivWidth = int(maxBitwidth / slices)
        bitRemaining = maxBitwidth % slices
        
        # list containing width of each variable slice
        keyDivWidthList = [keyDivWidth] * slices
            
        for i in range(bitRemaining):
            keyDivWidthList[i] += 1

        coeff = []
        for i in range(slices):
            coeff.append(random.randint(0, twoPowerK - 1))

        keyDivs = []
        msbPos = maxBitwidth - 1
        remSlices = 0
        for i in range(slices):
            lsbPos = msbPos - keyDivWidthList[i] + 1
            if lsbPos < varMap[originalKey]:
                keyDivs.append(extractExpr(msbPos, lsbPos, key))
                remSlices += 1
            msbPos = msbPos - keyDivWidthList[i]

        zxtndKeyDivs = []
        for i in range(remSlices):
            zxtndKeyDivs.append(zeroExtendExpr(newBitwidth - keyDivWidthList[i], keyDivs[i]))

        bvmulStrs = []
        for i in range(remSlices):
            bvmulList.append(bvmulExpr(constExpr(coeff[i], newBitwidth), zxtndKeyDivs[i]))


    lhsStr = functools.reduce(lambda x, y: bvaddExpr(x, y), bvmulList)

    s = zeroExtendExpr(k + 1, primeCoeff)
    r = random.randint(0, prime - 1)

    rhsStr = bvaddExpr(bvmulExpr(constExpr(prime, newBitwidth), s), constExpr(r, newBitwidth))
    constraint = eqExpr(lhsStr, rhsStr)
    return constraint, primeCoeffDecl, prime


# Function: parseSmt2File
# @param: smt2File - input SMT2 file
# @return: varmap - a map containing as key the names of the variables and value as their bitwidth
# @return: smtFilePrefix - string containing the initial part of smt2File (until start of 'assert' in 'smt2File')
#
# Creates variable map and also copies the initial part of SMT2 file (until start of 'assert' in 'smt2File')
# This would later be appended with our constraints to create the new SMT2 file
def parseSmt2FileVariables(smt2File):
    # create regex to specific lines
    compiledVarPattern = re.compile("[ \t]*\(declare-fun")
    compiledAssertPattern = re.compile("assert")

    # read variable info in map
    varMap = {}

    scriptName = os.path.basename(__file__)    
    smtFilePrefix = "; [" + scriptName + "] Autogenerated from source file: " + smt2File.name + "\n"
    for line in smt2File:
        smtFilePrefix += line
        if compiledVarPattern.search(line):
            wordList = line.split()
            varName = wordList[1]

            varWidthStr = wordList[-1].rstrip(")")
            if varWidthStr.isdigit():
                varWidth = int(varWidthStr)
                varMap[varName] = varWidth
        elif compiledAssertPattern.search(line):
            break

    return varMap, smtFilePrefix


# Function: parseSmt2File
# @param: smt2File - input SMT2 file
# @param: newConstraints - string which is a SMT2 constraint
# @return: smtFileSuffix - string containing our constraints followed by rest of input file
#
# returns a string after our adding our constraints to the rest of the input file
def parseSmt2FileSuffix(smt2File, newConstraints):
    compiledCheckSatPattern = re.compile("check-sat")

    smtFileSuffix = ""
    for line in smt2File:
        if compiledCheckSatPattern.search(line):
            smtFileSuffix += "(assert"
            smtFileSuffix += " " + newConstraints + ")\n"
            smtFileSuffix += line
            break
        smtFileSuffix += line

    # write everything after '(check-sat)'
    for line in smt2File:
        smtFileSuffix += line

    return smtFileSuffix

# Function: generateSMT2FileFromConstraints
def generateSMT2FileFromConstraints(smt2prefix, coeffDeclList, constraintList, smt2suffix, tempFileName):
    outputSMT2File = open(tempFileName, "w")
    outputSMT2File.write(smt2prefix)

    for decl in coeffDeclList:
        outputSMT2File.write(decl)

    outputSMT2File.write("(assert")

    strConstraints = functools.reduce(lambda x, y: andExpr(x, y), constraintList)
    outputSMT2File.write(strConstraints)

    outputSMT2File.write(")\n")
    outputSMT2File.write(smt2suffix)

    outputSMT2File.close()


# Function: generateSMT1FromSMT2File
def generateSMT1FromSMT2File(smt2FileName, smt1FileName):
    cmd = "boolector -ds1 -o " + smt1FileName + " " + smt2FileName
    return os.system(cmd)


# Funtion: countSolutions
def countSolutions(smtResultsFileName):
    smtResultsFile = open(smtResultsFileName, "r")
    count = 0
    hasTimedOut = False

    for line in smtResultsFile:
        if line == "sat\n":
            count += 1
        elif "unknown" in line:
            hasTimedOut = True

    return count, hasTimedOut


def getCommonPrimesAndMedian(runResults, logFile):
    commonPrimes = runResults[0][1]
    for i in range(1, len(runResults)):
        commonPrimes = commonPrimes & runResults[i][1]

    logFile.write("commomPrimes: " + str(list(commonPrimes.elements())) + "\n")

    valList = []
    for i in range(len(runResults)):
        # subResult = runResults[i][1].subtract(commonPrimes)
        subResult = runResults[i][1] - commonPrimes
        if subResult == None:
            valList.append(runResults[i][0])
        else:
            prod = 1
            for key in subResult:
                prod = prod * (key ** subResult[key])
            valList.append(prod * runResults[i][0])

    logFile.write("valList: " + str(valList) + "\n")
    return (list(commonPrimes.elements()), numpy.median(valList))
    

# Function: main
def main(argv):
    generateEquationConstraint.counter = 0;

    # check for correct number of arguments
    scriptName = os.path.basename(__file__)
    if len(argv) < 6:
        sys.stderr.write("Error: Invalid arguments.\n")
        sys.stderr.write("    [Usage]: " + scriptName + " <input_SMT2_file> <primes_file> <num_iterations> <log_file> <output_file>\n")
        sys.exit(1)

    # open files
    inputSMTFile = open(argv[1], "r")
    primesFile = open(argv[2], "r")
    numIterations = int(argv[3])
    logFile = open(argv[4], "w", 1)
    finalOutputFile = open(argv[5], "w", 1)
    # probMapFile = open(argv[3], "r")

    primesMap = populatePrimesMap(primesFile)
    # epsilonMap = populateEpsilonMap(probMapFile)

    (varMap, smt2prefix) = parseSmt2FileVariables(inputSMTFile)
    smt2suffix = parseSmt2FileSuffix(inputSMTFile, "true")

    maxBitwidth = max(varMap.values())
    # print("maxBitwidth: " + str(maxBitwidth))

    # find pivot solutions
    tempDir = os.getcwd() + "/temp_amc"
    smtSolver = os.path.dirname(os.path.realpath(__file__)) + "/../cvc4-mc/cvc4-1.4/build/src/main/cvc4"

    if not os.path.exists(tempDir):
        os.makedirs(tempDir)

    timeout = 2400
    minPivot = 1

    epsilon = 0.8 # epsilonMap[maxBitwidth]
    maxPivot = int(2*math.ceil(4.94*(1+1/epsilon)*(1+1/epsilon)))
    # print("maxPivot: " + str(maxPivot))

    scriptStartTime = os.times()
    logFile.write("Script start time: " + str(scriptStartTime) + "\n")

    logFile.write("Epsilon: " + str(epsilon) + "\n")
    logFile.write("maxPivot: " + str(maxPivot) + "\n")


    iterationRunResults = []
    timedOutRuns = set()
    for i in range(numIterations):
        tempSMT2FileName = tempDir + "/temp_" + str(i) + ".smt2"
        tempOutputFile = tempDir + "/solverResults_" + str(i) + ".txt"
        tempErrorFile = tempDir + "/solverErrors_" + str(i) + ".txt"

        slices = 2

        logFile.write("\n\n################################################################################\n")
        logFile.write("Iteration: " + str(i) + "\n")
        
        constraintList = []
        coeffDeclList = []
        primeList = []

        (constraint, coeffDecl, prime) = generateEquationConstraint(varMap, primesMap, maxBitwidth, slices)
        constraintList.append(constraint)
        coeffDeclList.append(coeffDecl)

        primeList.append(prime)

        innerLoopRun = 0
        while True:
            logFile.write("\n----\n")
            logFile.write("innerLoopRun: " + str(innerLoopRun) + "\n")
            innerLoopRun += 1

            generateSMT2FileFromConstraints(smt2prefix, coeffDeclList, constraintList, smt2suffix, tempSMT2FileName)

            cmd = smtSolver + " -im --tlimit=" + str(timeout * 1000) + " --maxsolutions=" + str(maxPivot) + " " + tempSMT2FileName + " >" + tempOutputFile + " 2>>" + tempErrorFile;
            logFile.write("cmd: " + cmd + "\n")
            
            startTime = os.times()
            os.system(cmd)
            endTime = os.times()

            logFile.write("startTime: " + str(startTime) + "\n")
            logFile.write("endTime: " + str(endTime) + "\n")
            logFile.write("cmd time: " + str(endTime.children_user + endTime.children_system - startTime.children_user - startTime.children_system) + "\n")

            hasTimedOut = False
            (numSolutions, hasTimedOut) = countSolutions(tempOutputFile)

            if hasTimedOut:
                timedOutRuns.add(i)

            logFile.write("numConstraints: " + str(len(constraintList)) + ", slices: " + str(slices) + ", numSolutions: " + str(numSolutions) + ", hasTimedOut: " + str(hasTimedOut) + "\n")
        
            if numSolutions >= maxPivot:
                (constraint, coeffDecl, prime) = generateEquationConstraint(varMap, primesMap, maxBitwidth, slices)
                constraintList.append(constraint)
                coeffDeclList.append(coeffDecl)
                primeList.append(prime)

            elif numSolutions >= minPivot and not hasTimedOut:
                break;

            elif numSolutions >= 0:
                constraintList.pop()
                coeffDeclList.pop()
                primeList.pop()

                if (slices >= maxBitwidth):
                    break

                slices = (slices * 2) if (slices * 2) < maxBitwidth else maxBitwidth;

                (constraint, coeffDecl, prime) = generateEquationConstraint(varMap, primesMap, maxBitwidth, slices)
                constraintList.append(constraint)
                coeffDeclList.append(coeffDecl)
                primeList.append(prime)

            logFile.flush()
            # raw_input("Press Enter to continue...")

        iterationRunResults.append((numSolutions, collections.Counter(primeList)))

    scriptEndTime = os.times()
    logFile.write("Script end time: " + str(scriptEndTime) + "\n")
    logFile.write("Total script time: " + str(scriptEndTime.children_user + scriptEndTime.children_system - scriptStartTime.children_user - scriptStartTime.children_system) + "\n")

    logFile.write("iterationRunResults: " + str(iterationRunResults) + "\n")

    (commonPrimes, med) = getCommonPrimesAndMedian(iterationRunResults, logFile)
    logFile.write("commonPrimes: " + str(commonPrimes) + ", median: " + str(med) + ", ")

    finalOutputFile.write(str(maxBitwidth) + ";")
    for primes in commonPrimes:
        finalOutputFile.write(str(primes) + ",")
    finalOutputFile.write(";" + str(med) + ";")

    finalOutputFile.write(str(scriptEndTime.children_user + scriptEndTime.children_system - scriptStartTime.children_user - scriptStartTime.children_system) + ";")
    finalOutputFile.write(str(len(timedOutRuns)) + ";")

    logFile.write("Timedout in runs: " + str(timedOutRuns) + ";")
    finalOutputFile.write("Timedout in runs: " + str(timedOutRuns))

    finalOutputFile.close()
    logFile.close()


if __name__ == "__main__":
    main(sys.argv)
