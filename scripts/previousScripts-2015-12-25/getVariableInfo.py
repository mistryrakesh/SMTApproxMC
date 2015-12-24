#!/home/rakeshmistry/bin/Python-3.4.3/bin/python3

# @author: rakesh mistry - 'inspire'
# @date: 2015-08-06

import sys
import re
import os
import math

# Function: parseSmt2File
def parseSmt2FileVariables(smt2File):
    compiledVarPattern = re.compile("[ \t]*\(declare-fun")
    varMap = {}

    for line in smt2File:
        if compiledVarPattern.search(line):
            wordList = line.split()
            varName = wordList[1]

            varWidthStr = wordList[-1].rstrip(")")
            if varWidthStr.isdigit():
                varWidth = int(varWidthStr)
                varMap[varName] = varWidth

    return varMap


# Function: main
def main(argv):
    # check for correct number of arguments
    scriptName = os.path.basename(__file__)
    if len(argv) < 3:
        sys.stderr.write("Error: Invalid arguments.\n")
        sys.stderr.write("    [Usage]: " + scriptName + " <input_SMT2_file> <output_file>\n")
        sys.exit(1)

    # open files
    inputSMTFile = open(argv[1], "r")
    finalOutputFile = open(argv[2], "w")

    varMap = parseSmt2FileVariables(inputSMTFile)

    maxBitwidth = max(varMap.values())

    singleBitVars = 0
    multiBitVars = 0
    for key in varMap.keys():
        if varMap[key] > 1:
            multiBitVars += 1
        else:
            singleBitVars += 1

    finalOutputFile.write(str(maxBitwidth) + ";" + str(len(varMap)) + ";" + str(multiBitVars) + ";" + str(singleBitVars))
    finalOutputFile.close()


if __name__ == "__main__":
    main(sys.argv)
