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
		CHECK_EQUAL(i, kthOrderStatistics.bruteforce(v,i));
		CHECK_EQUAL(i, kthOrderStatistics.orderselect(v,i));
		CHECK_EQUAL(i, kthOrderStatistics.kselect(v,i));
		CHECK_EQUAL(i, kthOrderStatistics.kheapsort(v,i));
		CHECK_EQUAL(i, kthOrderStatistics.heapselect(v,i));
		CHECK_EQUAL(i, kthOrderStatistics.quickselect(v,i));
	}

}

TEST(kthOrderStatisticsTest, testEqualInputs)
{
	
	KthOrderStatistics kthOrderStatistics;
	vector<int> v = {3,2,1,3,3};
	vector<int> r(v.begin(), v.end());
	sort(r.begin(), r.end());
	
	for(int i=0; i<(int)v.size(); i++){
		CHECK_EQUAL(r[i], kthOrderStatistics.bruteforce(v,i));
		CHECK_EQUAL(r[i], kthOrderStatistics.orderselect(v,i));
		CHECK_EQUAL(r[i], kthOrderStatistics.kselect(v,i));
		CHECK_EQUAL(r[i], kthOrderStatistics.kheapsort(v,i));
		CHECK_EQUAL(r[i], kthOrderStatistics.heapselect(v,i));
		CHECK_EQUAL(r[i], kthOrderStatistics.quickselect(v,i));
	}

}