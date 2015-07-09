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
#include "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../test/unit/expr/expr_public.h"

static ExprPublic suite_ExprPublic;

static CxxTest::List Tests_ExprPublic = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ExprPublic( "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../test/unit/expr/expr_public.h", 30, "ExprPublic", suite_ExprPublic, Tests_ExprPublic );

static class TestDescription_ExprPublic_testDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testDefaultCtor() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 109, "testDefaultCtor" ) {}
 void runTest() { suite_ExprPublic.testDefaultCtor(); }
} testDescription_ExprPublic_testDefaultCtor;

static class TestDescription_ExprPublic_testCtors : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testCtors() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 115, "testCtors" ) {}
 void runTest() { suite_ExprPublic.testCtors(); }
} testDescription_ExprPublic_testCtors;

static class TestDescription_ExprPublic_testAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testAssignment() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 142, "testAssignment" ) {}
 void runTest() { suite_ExprPublic.testAssignment(); }
} testDescription_ExprPublic_testAssignment;

static class TestDescription_ExprPublic_testEquality : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testEquality() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 156, "testEquality" ) {}
 void runTest() { suite_ExprPublic.testEquality(); }
} testDescription_ExprPublic_testEquality;

static class TestDescription_ExprPublic_testComparison : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testComparison() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 171, "testComparison" ) {}
 void runTest() { suite_ExprPublic.testComparison(); }
} testDescription_ExprPublic_testComparison;

static class TestDescription_ExprPublic_testGetKind : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testGetKind() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 216, "testGetKind" ) {}
 void runTest() { suite_ExprPublic.testGetKind(); }
} testDescription_ExprPublic_testGetKind;

static class TestDescription_ExprPublic_testGetNumChildren : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testGetNumChildren() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 233, "testGetNumChildren" ) {}
 void runTest() { suite_ExprPublic.testGetNumChildren(); }
} testDescription_ExprPublic_testGetNumChildren;

static class TestDescription_ExprPublic_testOperatorFunctions : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testOperatorFunctions() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 250, "testOperatorFunctions" ) {}
 void runTest() { suite_ExprPublic.testOperatorFunctions(); }
} testDescription_ExprPublic_testOperatorFunctions;

static class TestDescription_ExprPublic_testGetType : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testGetType() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 271, "testGetType" ) {}
 void runTest() { suite_ExprPublic.testGetType(); }
} testDescription_ExprPublic_testGetType;

static class TestDescription_ExprPublic_testToString : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testToString() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 290, "testToString" ) {}
 void runTest() { suite_ExprPublic.testToString(); }
} testDescription_ExprPublic_testToString;

static class TestDescription_ExprPublic_testToStream : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testToStream() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 307, "testToStream" ) {}
 void runTest() { suite_ExprPublic.testToStream(); }
} testDescription_ExprPublic_testToStream;

static class TestDescription_ExprPublic_testIsNull : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testIsNull() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 339, "testIsNull" ) {}
 void runTest() { suite_ExprPublic.testIsNull(); }
} testDescription_ExprPublic_testIsNull;

static class TestDescription_ExprPublic_testIsConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testIsConst() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 351, "testIsConst" ) {}
 void runTest() { suite_ExprPublic.testIsConst(); }
} testDescription_ExprPublic_testIsConst;

static class TestDescription_ExprPublic_testGetConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testGetConst() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 419, "testGetConst" ) {}
 void runTest() { suite_ExprPublic.testGetConst(); }
} testDescription_ExprPublic_testGetConst;

static class TestDescription_ExprPublic_testGetExprManager : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprPublic_testGetExprManager() : CxxTest::RealTestDescription( Tests_ExprPublic, suiteDescription_ExprPublic, 444, "testGetExprManager" ) {}
 void runTest() { suite_ExprPublic.testGetExprManager(); }
} testDescription_ExprPublic_testGetExprManager;

#include <cxxtest/Root.cpp>
