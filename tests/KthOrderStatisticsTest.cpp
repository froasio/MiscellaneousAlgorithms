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

TEST(kthOrderStatisticsTest, testQuickselectReturnsKthOrderStatistics)
{
	
	KthOrderStatistics kthOrderStatistics;
	vector<int> v(100);
	iota (v.begin(), v.end(), 1);
	for(int i=1; i<=(int)v.size(); i++){
		random_shuffle(v.begin(), v.end());
		CHECK_EQUAL(i, kthOrderStatistics.quickselect(v,i));
	}

}

TEST(kthOrderStatisticsTest, testKheapsortReturnsKthOrderStatistics)
{
	
	KthOrderStatistics kthOrderStatistics;
	vector<int> v(100);
	iota (v.begin(), v.end(), 1);
	for(int i=1; i<=(int)v.size(); i++){
		random_shuffle(v.begin(), v.end());
		CHECK_EQUAL(i, kthOrderStatistics.kheapsort(v,i));
	}

}