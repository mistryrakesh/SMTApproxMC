/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../test/unit/expr/type_cardinality_public.h"

static TypeCardinalityPublic suite_TypeCardinalityPublic;

static CxxTest::List Tests_TypeCardinalityPublic = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TypeCardinalityPublic( "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../test/unit/expr/type_cardinality_public.h", 32, "TypeCardinalityPublic", suite_TypeCardinalityPublic, Tests_TypeCardinalityPublic );

static class TestDescription_TypeCardinalityPublic_testTheBasics : public CxxTest::RealTestDescription {
public:
 TestDescription_TypeCardinalityPublic_testTheBasics() : CxxTest::RealTestDescription( Tests_TypeCardinalityPublic, suiteDescription_TypeCardinalityPublic, 45, "testTheBasics" ) {}
 void runTest() { suite_TypeCardinalityPublic.testTheBasics(); }
} testDescription_TypeCardinalityPublic_testTheBasics;

static class TestDescription_TypeCardinalityPublic_testArrays : public CxxTest::RealTestDescription {
public:
 TestDescription_TypeCardinalityPublic_testArrays() : CxxTest::RealTestDescription( Tests_TypeCardinalityPublic, suiteDescription_TypeCardinalityPublic, 51, "testArrays" ) {}
 void runTest() { suite_TypeCardinalityPublic.testArrays(); }
} testDescription_TypeCardinalityPublic_testArrays;

static class TestDescription_TypeCardinalityPublic_testUnaryFunctions : public CxxTest::RealTestDescription {
public:
 TestDescription_TypeCardinalityPublic_testUnaryFunctions() : CxxTest::RealTestDescription( Tests_TypeCardinalityPublic, suiteDescription_TypeCardinalityPublic, 73, "testUnaryFunctions" ) {}
 void runTest() { suite_TypeCardinalityPublic.testUnaryFunctions(); }
} testDescription_TypeCardinalityPublic_testUnaryFunctions;

static class TestDescription_TypeCardinalityPublic_testBinaryFunctions : public CxxTest::RealTestDescription {
public:
 TestDescription_TypeCardinalityPublic_testBinaryFunctions() : CxxTest::RealTestDescription( Tests_TypeCardinalityPublic, suiteDescription_TypeCardinalityPublic, 95, "testBinaryFunctions" ) {}
 void runTest() { suite_TypeCardinalityPublic.testBinaryFunctions(); }
} testDescription_TypeCardinalityPublic_testBinaryFunctions;

static class TestDescription_TypeCardinalityPublic_testTernaryFunctions : public CxxTest::RealTestDescription {
public:
 TestDescription_TypeCardinalityPublic_testTernaryFunctions() : CxxTest::RealTestDescription( Tests_TypeCardinalityPublic, suiteDescription_TypeCardinalityPublic, 179, "testTernaryFunctions" ) {}
 void runTest() { suite_TypeCardinalityPublic.testTernaryFunctions(); }
} testDescription_TypeCardinalityPublic_testTernaryFunctions;

static class TestDescription_TypeCardinalityPublic_testUndefinedSorts : public CxxTest::RealTestDescription {
public:
 TestDescription_TypeCardinalityPublic_testUndefinedSorts() : CxxTest::RealTestDescription( Tests_TypeCardinalityPublic, suiteDescription_TypeCardinalityPublic, 195, "testUndefinedSorts" ) {}
 void runTest() { suite_TypeCardinalityPublic.testUndefinedSorts(); }
} testDescription_TypeCardinalityPublic_testUndefinedSorts;

static class TestDescription_TypeCardinalityPublic_testBitvectors : public CxxTest::RealTestDescription {
public:
 TestDescription_TypeCardinalityPublic_testBitvectors() : CxxTest::RealTestDescription( Tests_TypeCardinalityPublic, suiteDescription_TypeCardinalityPublic, 202, "testBitvectors" ) {}
 void runTest() { suite_TypeCardinalityPublic.testBitvectors(); }
} testDescription_TypeCardinalityPublic_testBitvectors;

#include <cxxtest/Root.cpp>
