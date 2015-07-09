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
#include "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../test/unit/expr/expr_manager_public.h"

static ExprManagerPublic suite_ExprManagerPublic;

static CxxTest::List Tests_ExprManagerPublic = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ExprManagerPublic( "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../test/unit/expr/expr_manager_public.h", 30, "ExprManagerPublic", suite_ExprManagerPublic, Tests_ExprManagerPublic );

static class TestDescription_ExprManagerPublic_testMkAssociative : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprManagerPublic_testMkAssociative() : CxxTest::RealTestDescription( Tests_ExprManagerPublic, suiteDescription_ExprManagerPublic, 80, "testMkAssociative" ) {}
 void runTest() { suite_ExprManagerPublic.testMkAssociative(); }
} testDescription_ExprManagerPublic_testMkAssociative;

static class TestDescription_ExprManagerPublic_testMkAssociative2 : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprManagerPublic_testMkAssociative2() : CxxTest::RealTestDescription( Tests_ExprManagerPublic, suiteDescription_ExprManagerPublic, 95, "testMkAssociative2" ) {}
 void runTest() { suite_ExprManagerPublic.testMkAssociative2(); }
} testDescription_ExprManagerPublic_testMkAssociative2;

static class TestDescription_ExprManagerPublic_testMkAssociative3 : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprManagerPublic_testMkAssociative3() : CxxTest::RealTestDescription( Tests_ExprManagerPublic, suiteDescription_ExprManagerPublic, 106, "testMkAssociative3" ) {}
 void runTest() { suite_ExprManagerPublic.testMkAssociative3(); }
} testDescription_ExprManagerPublic_testMkAssociative3;

static class TestDescription_ExprManagerPublic_testMkAssociativeTooFew : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprManagerPublic_testMkAssociativeTooFew() : CxxTest::RealTestDescription( Tests_ExprManagerPublic, suiteDescription_ExprManagerPublic, 119, "testMkAssociativeTooFew" ) {}
 void runTest() { suite_ExprManagerPublic.testMkAssociativeTooFew(); }
} testDescription_ExprManagerPublic_testMkAssociativeTooFew;

static class TestDescription_ExprManagerPublic_testMkAssociativeBadKind : public CxxTest::RealTestDescription {
public:
 TestDescription_ExprManagerPublic_testMkAssociativeBadKind() : CxxTest::RealTestDescription( Tests_ExprManagerPublic, suiteDescription_ExprManagerPublic, 124, "testMkAssociativeBadKind" ) {}
 void runTest() { suite_ExprManagerPublic.testMkAssociativeBadKind(); }
} testDescription_ExprManagerPublic_testMkAssociativeBadKind;

#include <cxxtest/Root.cpp>
