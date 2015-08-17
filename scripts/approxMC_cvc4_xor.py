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

def bvxorExpr(var1, var2):
    return "(bvxor " + str(var1) + " " + str(var2) + ")"

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


# Function: generateEquationConstraint
# @param: varmap - a map of variables with key as variable name and value being
#         its width
#
# Generates an constraint of the form:
#     a[0] XOR a[2] XOR ... XOR b[4] ... = {0, 1}
def generateXorConstraint(varMap):
    xorBitList = []
    for key in varMap.keys():
        for i in range(varMap[key]):
            if random.random() >= 0.5:
                xorBitList.append(extractExpr(i, i, key))

    lhsStr = functools.reduce(lambda x, y: bvxorExpr(x, y), xorBitList)
    rhsStr = "#b1" if (random.random() >= 0.5) else  "#b0"

    return eqExpr(lhsStr, rhsStr)


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
def generateSMT2FileFromConstraints(smt2prefix, constraintList, lastAssertLine, smt2suffix, tempFileName):
    outputSMT2File = open(tempFileName, "w")
    outputSMT2File.write(smt2prefix)

    if len(constraintList) > 0:
        outputSMT2File.write("(assert")
        strConstraints = functools.reduce(lambda x, y: andExpr(x, y), constraintList)
        outputSMT2File.write(strConstraints)
        outputSMT2File.write(")\n")

    outputSMT2File.write(lastAssertLine)
    outputSMT2File.write(smt2suffix)

    outputSMT2File.close()


# Funtion: countSolutions
def countSolutions(smtResultsFileName):
    smtResultsFile = open(smtResultsFileName, "r")
    count = 0

    for line in smtResultsFile:
        if line == "sat\n":
            count += 1

    return count


# Function: getCommonIterationsAndMedian
def getCommonIterationsAndMedian(iterationRunResults):
    commonIterations = min([i[0] for i in iterationRunResults])

    valList = []
    for (numIterations, numSolutions) in iterationRunResults:
        valList.append(2 ** (numIterations - commonIterations) * numSolutions)

    return (commonIterations, numpy.median(valList))


# Function: main
def main(argv):
    # check for correct number of arguments
    scriptName = os.path.basename(__file__)
    if len(argv) < 5:
        sys.stderr.write("Error: Invalid arguments.\n")
        sys.stderr.write("    [Usage]: " + scriptName + " <input_SMT2_file> <num_iterations> <log_file> <output_file>\n")
        sys.exit(1)

    # open files
    inputSMTFile = open(argv[1], "r")
    numIterations = int(argv[2])
    logFile = open(argv[3], "w", 1)
    finalOutputFile = open(argv[4], "w", 1)

    (varMap, smt2prefix, lastAssertLine) = parseSmt2FileVariables(inputSMTFile)
    smt2suffix = parseSmt2FileSuffix(inputSMTFile, "true")

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
        tempSMT1FileName = tempDir + "/temp_" + str(i) + ".smt1"

        logFile.write("\n\n################################################################################\n")
        logFile.write("Iteration: " + str(i) + "\n")
        
        constraintList = []

        innerLoopRun = 0
        hasTimedOut = False
        numSolutions = 0

        while True:
            logFile.write("\n----\n")
            logFile.write("innerLoopRun: " + str(innerLoopRun) + "\n")
            innerLoopRun += 1

            generateSMT2FileFromConstraints(smt2prefix, constraintList, lastAssertLine, smt2suffix, tempSMT2FileName)

            cmd = "doalarm -t profile " + str(timeout) + " " + smtSolver + " -im --maxsolutions=" + str(maxPivot) + " --bitblast=eager " + tempSMT2FileName + " >" + tempOutputFile + " 2>>" + tempErrorFile
            logFile.write("cmd: " + cmd + "\n")
            
            startTime = os.times()
            os.system(cmd)
            endTime = os.times()

            logFile.write("startTime: " + str(startTime) + "\n")
            logFile.write("endTime: " + str(endTime) + "\n")
            logFile.write("cmd time: " + str(endTime.elapsed - startTime.elapsed) + "\n")

            hasTimedOut = False
            if (endTime.elapsed - startTime.elapsed) > (timeout - 10):
                hasTimedOut = True

            numSolutions = countSolutions(tempOutputFile)

            logFile.write("numSolutions: " + str(numSolutions) + ", hasTimedOut: " + str(hasTimedOut) + "\n")

            if numSolutions >= maxPivot:
                constraint = generateXorConstraint(varMap)
                constraintList.append(constraint)

            else:
                break

            logFile.flush()
            # raw_input("Press Enter to continue...")

        iterationRunResults.append((len(constraintList), numSolutions))

        if hasTimedOut:
            timedOutRuns.add(i)


    scriptEndTime = os.times()
    logFile.write("Script end time: " + str(scriptEndTime) + "\n")
    logFile.write("Total script time: " + str(scriptEndTime.children_user + scriptEndTime.children_system - scriptStartTime.children_user - scriptStartTime.children_system) + "\n")

    logFile.write("iterationRunResults: " + str(iterationRunResults) + "\n")

    (commonIterations, median) = getCommonIterationsAndMedian(iterationRunResults)

    finalOutputFile.write(str(commonIterations) + ";")
    finalOutputFile.write(str(median) + ";")

    finalOutputFile.write(str(scriptEndTime.children_user + scriptEndTime.children_system - scriptStartTime.children_user - scriptStartTime.children_system) + ";")

    logFile.write("Timedout in runs: " + str(timedOutRuns))
    finalOutputFile.write(str(len(timedOutRuns)) + ";")
    finalOutputFile.write("Timedout in runs: " + str(timedOutRuns))

    finalOutputFile.close()
    logFile.close()


if __name__ == "__main__":
    main(sys.argv)
