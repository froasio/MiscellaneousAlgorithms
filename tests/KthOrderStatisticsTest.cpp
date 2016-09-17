#include "CppUTest/TestHarness.h"
#include "KthOrderStatistics.h"

using namespace std;

TEST_GROUP(kthOrderStatisticsTest)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(kthOrderStatisticsTest, testThatTestsWorks)
{
	
	KthOrderStatistics kthOrderStatistics;
	CHECK_EQUAL(true, kthOrderStatistics.getTrue());

}
