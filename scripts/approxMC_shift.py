#!/home/rakeshmistry/bin/Python-3.4.3/bin/python3

# @author: rakesh mistry
# @date: 2016-06-20

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

def bvuremExpr(var1, var2):
    return "(bvurem " + str(var1) + " " + str(var2) + ")"

def bvlshrExpr(var1, num):
    return "(bvlshr " + str(var1) + " " + str(num) + ")"

################################################################################


# Function: populatePrimesMap
# @param: primesMap - file containing primes.
#         Each line is of the form "k prime"
#         where for every number 'k' the value of 'prime' is smallest prime > 2^k
#
# @return: map of prime numbers for 2^k (1 <= k <= 100 in our file)
def populatePrimesMap(primesFile):
    primesMap = {}
    for line in primesFile:
        strList = line.split()
        primesMap[int(strList[0])] = int(strList[1])

    return primesMap


# Function: generateCoeff
# @param: n - number of coefficients to generate
# @param: p - max value of coefficient
def generateCoeff(n, p):
    coeff = []
    for i in range(n):
        coeff.append(random.randrange(1, p - 1, 2)) # randomly select an odd number between 1 and (p - 1)

    return coeff


# Function: generateEquationConstraint
# @param: varmap - a map of variables with key as variable name and value being
#         its width
# @param: k - maximum bitwidth among all variables
# @param: l - amount to shift
#
# Generates an equation of the form:
#     (a1x1 + a2x2 + ...) div 2^(k-l) = r
def generateEquationConstraint(varMap, prime, k, l):

    bvmulList = []
    for key in varMap.keys():
        originalKey = key
        if varMap[key] != k:
            key = zeroExtendExpr(k - varMap[key], key)

        coeff = generateCoeff(1, 2 ** k) # generate odd ai
        bvmulStrs = [] # list of strings representing each 'aixi'
        bvmulList.append(bvmulExpr(constExpr(coeff[0], k), key))

    # generate string representing 'a1x1 + a2x2 + ...'
    lhsStr = functools.reduce(lambda x, y: bvaddExpr(x, y), bvmulList)

    # generate string representing '(a1x1 + a2x2 + ...) bvlshr (k - l)'
    lhsStr = bvlshrExpr(lhsStr, constExpr(int(k - l), k))

    r = random.randint(0, 2 ** l)
    rhsStr = constExpr(r, k)

    # generate string representing '(a1x1 + a2x2 + ...) mod p = r'
    constraint = eqExpr(lhsStr, rhsStr)
    return constraint


# Function: parseSmt2File
# @param: smt2File - input SMT2 file
#
# @return: varmap - a map containing as key the names of the variables and value as their bitwidth
# @return: smtFilePrefix - string containing the initial part of smt2File (until start of 'assert' in 'smt2File')
# @return: assertLine - the first 'assert' line in 'smt2File'
#
# Creates variable map and also copies the initial part of SMT2 file (until start of 'assert' in 'smt2File')
# This would later be appended with our constraints to create the new SMT2 file
def parseSmt2FileVariables(smt2File):
    # create regex to specific lines
    compiledVarPattern = re.compile("[ \t]*\(declare-fun")
    compiledAssertPattern = re.compile("assert")

    # read variable info in map
    varMap = {}
    assertLine = ""

    scriptName = os.path.basename(__file__)    
    smtFilePrefix = "; [" + scriptName + "] Autogenerated from source file: " + smt2File.name + "\n"
    for line in smt2File:
        if compiledAssertPattern.search(line):
            assertLine = line
            break;

        smtFilePrefix += line
        if compiledVarPattern.search(line):
            wordList = line.split()
            varName = wordList[1]

            varWidthStr = wordList[-1].rstrip(")")
            if varWidthStr.isdigit():
                varWidth = int(varWidthStr)
                varMap[varName] = varWidth

    return varMap, smtFilePrefix, assertLine


# Function: parseSmt2FileSuffix
# @param: smt2File - input SMT2 file
# @param: newConstraints - string which is a SMT2 constraint
#
# @return: smtFileSuffix - string containing our constraints followed by rest of input file
#
# returns a string after our adding our constraints to the rest of the input file
#
# TODO: why are adding 'newConstraints' here which is basically 'true' when called
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
# @param: smt2prefix - prefix portion of input smt2 file (this contains all lines
#         of smt2 file until the first 'assert')
# @param: assertLine - the assert line returned by function 'parseSmt2FileVariables'
# @param: constraintList - a list of generated constraints
# @param: smt2suffix - rest of input smt2 file
# @param: outFileName - name of generated output smt2 file
#
# The function generates an smt2 files after adding our constraints to the
# original input file

def generateSMT2FileFromConstraints(smt2prefix, assertLine, constraintList, smt2suffix, outFileName):
    outputSMT2File = open(outFileName, "w")
    outputSMT2File.write(smt2prefix)

    outputSMT2File.write("(assert")

    strConstraints = functools.reduce(lambda x, y: andExpr(x, y), constraintList)
    outputSMT2File.write(strConstraints)

    outputSMT2File.write(")\n")
    outputSMT2File.write(assertLine)
    outputSMT2File.write(smt2suffix)

    outputSMT2File.close()


# Function: generateSMT1FromSMT2File
# @param: smt2FileName - name of generated smt2 file
# @param: smt1FileName - name of output smt1 file from smt2 file
#
# @return: status of executing the command which generated the smt2 file
#
# The function generates an smt1 equivalent file from given smt2 file.
# This is required by boolector since it does not support incremental mode in
# SMT2 files
def generateSMT1FromSMT2File(smt2FileName, smt1FileName):
    cmd = "boolector -ds1 -o " + smt1FileName + " " + smt2FileName
    return os.system(cmd)


# Funtion: countSolutions
# @param: smtResultsFileName - name of file containing 'sat' for each model
#         generated
#
# Counts the number of 'sat' in smtResultsFile which gives the number of models
def countSolutions(smtResultsFileName):
    smtResultsFile = open(smtResultsFileName, "r")
    count = 0

    for line in smtResultsFile:
        if line == "sat\n":
            count += 1

    return count

# Function: getCommonLsAndMedian
# @param: runResults - a tuple containing number of solutions and counter of
#         'l's
# @param: logFile - file on which log is written
#
# @return: list of common 'l's among all runs
# @return: median of remaining non-common elements
#
# For each run 'runResults' contains the list of Ls and number of solutions
# generated in the last case. This function extracts out the common Ls of
# all the runs and median of number of solutions times the non-common Ls
def getCommonLsAndMedian(runResults, logFile):
    commonLs = runResults[0][1]
    for i in range(1, len(runResults)):
        commonLs = commonLs & runResults[i][1]

    logFile.write("commomLs: " + str(list(commonLs.elements())) + "\n")

    valList = []
    for i in range(len(runResults)):
        # subResult = runResults[i][1].subtract(commonLs)
        subResult = runResults[i][1] - commonLs
        if subResult == None:
            valList.append(runResults[i][0])
        else:
            prod = 1
            for key in subResult:
                prod = prod * (key ** subResult[key])
            valList.append(prod * runResults[i][0])

    logFile.write("valList: " + str(valList) + "\n")
    return (list(commonLs.elements()), numpy.median(valList))


# Function: modelCounter
# Approximate model counter for a given smt2 input file
def modelCounter(varMap, prime, k, l, smt2prefix, assertLine, smt2suffix, timeout, minPivot, maxPivot, logFile, tempDir, i):
    smtSolver = os.path.dirname(os.path.realpath(__file__)) + "/../boolector-mc/boolector/boolector"

    tempSMT2FileNamePrefix = tempDir + "/temp_" + str(i)
    tempOutputFilePrefix = tempDir + "/solverResults_" + str(i)
    tempErrorFilePrefix = tempDir + "/solverErrors_" + str(i)
    tempSMT1FileNamePrefix = tempDir + "/temp_" + str(i)

    constraintList = [] # list of constraints each of form '(a1x1 + a2x2 + ...) div 2^(k-l) = r'
    lList = [] # list of 'l' values used to used to generate the constraints

    constraint = generateEquationConstraint(varMap, prime, k, l)
    constraintList.append(constraint)
    lList.append(l)

    innerLoopRun = 0 # loop counter
    foundCounts = False # set to true when 0 < #sols < maxPivots
    saveL = 0
    saveNumSolutions = -1

    while True:
        logFile.write("\n----\n")
        logFile.write("innerLoopRun: " + str(innerLoopRun) + "\n")
        
        tempSMT2FileName = tempSMT2FileNamePrefix + "_" + str(innerLoopRun) + ".smt2"
        tempSMT1FileName = tempSMT1FileNamePrefix + "_" + str(innerLoopRun) + ".smt1"
        tempOutputFile = tempOutputFilePrefix + "_" + str(innerLoopRun) + ".txt"
        tempErrorFile = tempErrorFilePrefix + "_" + str(innerLoopRun) + ".txt"
        innerLoopRun += 1

        # generate smt1 file after adding our constraints
        generateSMT2FileFromConstraints(smt2prefix, assertLine, constraintList, smt2suffix, tempSMT2FileName)
        conversionResult = generateSMT1FromSMT2File(tempSMT2FileName, tempSMT1FileName)
        if conversionResult != 0:
            sys.stderr.write("Error while converting from SMT2 File to SMT1 file. Aborting ...\n")
            logFile.write("Error while converting from SMT2 File to SMT1 file. Aborting ...\n")
            logFile.close()
            exit(1)

        # call boolector for model counting
        cmd = "doalarm -t profile " + str(timeout) + " " + smtSolver + " -i -m --maxsolutions=" + str(maxPivot) + " " + tempSMT1FileName + " >" + tempOutputFile + " 2>>" + tempErrorFile;
        logFile.write("cmd: " + cmd + "\n")
        
        startTime = os.times()
        os.system(cmd)
        endTime = os.times()

        logFile.write("startTime: " + str(startTime) + "\n")
        logFile.write("endTime: " + str(endTime) + "\n")
        logFile.write("cmd time: " + str(endTime.elapsed - startTime.elapsed) + "\n")
        logFile.write("Current 'l' list: " + str(lList) + "\n")

        hasTimedOut = False
        if (endTime.elapsed - startTime.elapsed) > (timeout - 10):
            hasTimedOut = True

        numSolutions = countSolutions(tempOutputFile)

        logFile.write("numConstraints: " + str(len(constraintList)) + ", numSolutions: " + str(numSolutions) + ", hasTimedOut: " + str(hasTimedOut) + "\n")
    

        if numSolutions >= maxPivot:
            if foundCounts:
                logFile.write("Stopping after foundCounts = True and l <= 1\n")
                lList.pop();
                lList.append(saveL) # restore previous value of l
                numSolutions = saveNumSolutions # restore previous count of solutions
                break
            
            constraint = generateEquationConstraint(varMap, prime, k, l)
            constraintList.append(constraint)
            lList.append(l)

        elif numSolutions >= minPivot and not hasTimedOut:
            foundCounts = True

            if (l <= 1):
                logFile.write("Stopping after foundCounts = True and no further right shift possible\n")
                break

            constraintList.pop()
            saveL = lList.pop()
            saveNumSolutions = numSolutions

            l = int((l / 2) if (l / 2) > 1 else 1)

            constraint = generateEquationConstraint(varMap, prime, k, l)
            constraintList.append(constraint)
            lList.append(l)

        elif numSolutions >= 0:
            if (l <= 1):
                if hasTimedOut:
                    timedOutRuns.add(i)
                break

            constraintList.pop()
            lList.pop()

            l = int((l / 2) if (l / 2) > 1 else 1)

            constraint = generateEquationConstraint(varMap, prime, k, l)
            constraintList.append(constraint)
            lList.append(l)

        logFile.flush()

    return (numSolutions, collections.Counter(lList))


# Function: main
# @param: argv - command line arguments
def main(argv):
    # check for correct number of arguments
    scriptName = os.path.basename(__file__)
    if len(argv) != 6:
        sys.stderr.write("Error: Invalid arguments.\n")
        sys.stderr.write("    [Usage]: " + scriptName + " <input_SMT2_file> <primes_file> <num_iterations> <log_file> <output_file>\n")
        sys.exit(1)

    # open necessary files
    inputSMTFile = open(argv[1], "r")
    primesFile = open(argv[2], "r")
    numIterations = int(argv[3])
    logFile = open(argv[4], "w", 1)
    finalOutputFile = open(argv[5], "w", 1)

    primesMap = populatePrimesMap(primesFile)

    (varMap, smt2prefix, assertLine) = parseSmt2FileVariables(inputSMTFile)
    smt2suffix = parseSmt2FileSuffix(inputSMTFile, "true")

    k = max(varMap.values())

    tempDir = os.getcwd() + "/temp_amc"

    if not os.path.exists(tempDir):
        os.makedirs(tempDir)

    # define some constants
    timeout = 2400
    minPivot = 1
    epsilon = 0.8
    maxPivot = int(2*math.ceil(4.94*(1+1/epsilon)*(1+1/epsilon)))

    scriptStartTime = os.times()
    logFile.write("Script start time: " + str(scriptStartTime) + "\n")

    logFile.write("k: " + str(k) + "\n")
    logFile.write("Epsilon: " + str(epsilon) + "\n")
    logFile.write("maxPivot: " + str(maxPivot) + "\n")

    iterationRunResults = [] # list storing all 'l's and number of solutions for all iterations
    timedOutRuns = set() # set containing the iterations which timed out

    for i in range(numIterations):
        l = k - 1 # start with division by 2

        logFile.write("\n\n################################################################################\n")
        logFile.write("Iteration: " + str(i) + "\n")

        # perform approximate model counting
        iterationRunResults.append(modelCounter(varMap, primesMap[k], k, l, smt2prefix, assertLine, smt2suffix, timeout, minPivot, maxPivot, logFile, tempDir, i))


    scriptEndTime = os.times()
    logFile.write("Script end time: " + str(scriptEndTime) + "\n")
    logFile.write("Total script time: " + str(scriptEndTime.children_user + scriptEndTime.children_system - scriptStartTime.children_user - scriptStartTime.children_system) + "\n")

    logFile.write("iterationRunResults: " + str(iterationRunResults) + "\n")

    # compute primes and median from all iterations
    (commonLs, med) = getCommonLsAndMedian(iterationRunResults, logFile)

    logFile.write("commonLs: " + str(commonLs) + ", median: " + str(med) + ", ")

    # write important results in 'finalOutputFile' which is of the form
    #     <k> ; <list_of_common_primes>,<median> ; <total_time_of_script> ; <# timed_out_iterations> ; <list_of_iterations_timed_out>
    finalOutputFile.write(str(k) + ";")
    for primes in commonLs:
        finalOutputFile.write(str(primes) + ",")
    finalOutputFile.write(";" + str(med) + ";")

    finalOutputFile.write(str(scriptEndTime.children_user + scriptEndTime.children_system - scriptStartTime.children_user - scriptStartTime.children_system) + ";")
    finalOutputFile.write(str(len(timedOutRuns)) + ";")

    logFile.write("Timedout in runs: " + str(timedOutRuns) + ";")
    finalOutputFile.write("Timedout in runs: " + str(timedOutRuns))

    finalOutputFile.close()
    logFile.close()


# program entry - call main function
if __name__ == "__main__":
    main(sys.argv)
