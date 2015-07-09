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
#include "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../test/unit/util/cardinality_public.h"

static CardinalityPublic suite_CardinalityPublic;

static CxxTest::List Tests_CardinalityPublic = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CardinalityPublic( "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../test/unit/util/cardinality_public.h", 26, "CardinalityPublic", suite_CardinalityPublic, Tests_CardinalityPublic );

static class TestDescription_CardinalityPublic_testCardinalities : public CxxTest::RealTestDescription {
public:
 TestDescription_CardinalityPublic_testCardinalities() : CxxTest::RealTestDescription( Tests_CardinalityPublic, suiteDescription_CardinalityPublic, 31, "testCardinalities" ) {}
 void runTest() { suite_CardinalityPublic.testCardinalities(); }
} testDescription_CardinalityPublic_testCardinalities;

#include <cxxtest/Root.cpp>
