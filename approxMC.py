#!/usr/bin/python

# @author: rakesh mistry - 'inspire'
# @date: 2015-06-14

import sys
import re
import os
import math
import random

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

    newBitwidth = k + int(math.ceil(math.log(slices * len(varMap), 2))) + 1 # +1 since 's' can be upto 'prime-1'

    primeCoeff = "temp_prime_coeff_" + str(generateEquationConstraint.counter)
    primeCoeffDecl = "(declare-fun " + primeCoeff + " () (_ BitVec " + str(newBitwidth - (k + 1)) + "))\n"

    bvmulList = []
    for key in varMap.keys():
        if varMap[key] != maxBitwidth:
            key = zeroExtendExpr(maxBitwidth - varMap[key], key)

        assert maxBitwidth >= slices

        # find slice widths of variable
        keyDivWidth = maxBitwidth / slices
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
        for i in range(slices):
            keyDivs.append(extractExpr(msbPos, msbPos - keyDivWidthList[i] + 1, key))
            msbPos = msbPos - keyDivWidthList[i]

        zxtndKeyDivs = []
        for i in range(slices):
            zxtndKeyDivs.append(zeroExtendExpr(newBitwidth - keyDivWidthList[i], keyDivs[i]))

        bvmulStrs = []
        for i in range(slices):
            bvmulList.append(bvmulExpr(constExpr(coeff[i], newBitwidth), zxtndKeyDivs[i]))


    lhsStr = reduce(lambda x, y: bvaddExpr(x, y), bvmulList)

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

    strConstraints = reduce(lambda x, y: andExpr(x, y), constraintList)
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

    for line in smtResultsFile:
        if line == "sat\n":
            count += 1

    return count


# Function: main
def main(argv):
    global numVars
    global tempPrimeCoeffList
    generateEquationConstraint.counter = 0;

    # check for correct number of arguments
    scriptName = os.path.basename(__file__)
    if len(argv) < 4:
        sys.stderr.write("Error: Invalid arguments.\n")
        sys.stderr.write("    [Usage]: " + scriptName + " <input_SMT2_file> <primes_file> <prob_map_file>\n")
        sys.exit(1)

    # open files
    inputSMTFile = open(argv[1], "r")
    primesFile = open(argv[2], "r")
    probMapFile = open(argv[3], "r")

    primesMap = populatePrimesMap(primesFile)
    epsilonMap = populateEpsilonMap(probMapFile)

    (varMap, smt2prefix) = parseSmt2FileVariables(inputSMTFile)
    smt2suffix = parseSmt2FileSuffix(inputSMTFile, "true")

    maxBitwidth = max(varMap.values())
    # print "maxBitwidth: " + str(maxBitwidth)

    # find pivot solutions
    tempDir = os.getcwd() + "/temp_amc"
    smtSolver = "boolector-mc/boolector/boolector"

    tempSMT2FileName = tempDir + "/temp.smt2"
    tempOutputFile = tempDir + "/solverResults.txt"
    tempErrorFile = tempDir + "/solverErrors.txt"
    tempSMT1FileName = tempDir + "/temp.smt1"

    constraintList = []
    coeffDeclList = []
    primeList = []

    if not os.path.exists(tempDir):
        os.makedirs(tempDir)

    slices = 2
    timeout = 2500
    minPivot = 1

    epsilon = 0.8 # epsilonMap[maxBitwidth]
    maxPivot = int(2*math.ceil(4.94*(1+1/epsilon)*(1+1/epsilon)))
    print "maxPivot: " + str(maxPivot)

    (constraint, coeffDecl, prime) = generateEquationConstraint(varMap, primesMap, maxBitwidth, slices)
    constraintList.append(constraint)
    coeffDeclList.append(coeffDecl)
    primeList.append(prime)

    while True:
        generateSMT2FileFromConstraints(smt2prefix, coeffDeclList, constraintList, smt2suffix, tempSMT2FileName)
        conversionResult = generateSMT1FromSMT2File(tempSMT2FileName, tempSMT1FileName)
        if conversionResult != 0:
            sys.stderr.write("Error while converting from SMT2 File to SMT1 file. Aborting ...\n")
            exit(1)

        cmd = smtSolver + " -i -m -t " + str(timeout) + " --maxsolutions=" + str(maxPivot) + " " + tempSMT1FileName + " >" + tempOutputFile + " 2>>" + tempErrorFile;
        os.system(cmd)
        numSolutions = countSolutions(tempOutputFile)

        # print "numConstraints: " + str(len(constraintList)) + ", slices: " + str(slices) + ", numSolutions: " + str(numSolutions)
        
        if numSolutions >= maxPivot:
            (constraint, coeffDecl, prime) = generateEquationConstraint(varMap, primesMap, maxBitwidth, slices)
            constraintList.append(constraint)
            coeffDeclList.append(coeffDecl)
            primeList.append(prime)

        elif numSolutions >= minPivot:
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

        # raw_input("Press Enter to continue...")

    print "numSolutions: " + str(numSolutions)
    print "primeList: " + str(primeList)

if __name__ == "__main__":
    main(sys.argv)
