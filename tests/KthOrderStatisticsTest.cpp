#include "CppUTest/TestHarness.h"
#include "KthOrderStatistics.h"
#include <numeric> 
#include <algorithm>

TEST_GROUP(kthOrderStatisticsTest)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(kthOrderStatisticsTest, testRandomInputs)
{
	
	KthOrderStatistics kthOrderStatistics;
	vector<int> v(100);
	iota (v.begin(), v.end(), 0);
	for(int i=0; i<(int)v.size(); i++){
		random_shuffle(v.begin(), v.end());
		CHECK_EQUAL(i, kthOrderStatistics.orderselect(v,i));
		CHECK_EQUAL(i, kthOrderStatistics.kheapsort(v,i));
		CHECK_EQUAL(i, kthOrderStatistics.quickselect(v,i));
	}

}