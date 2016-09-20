#ifndef KTH_ORDER_STATISTICS_H
#define KTH_ORDER_STATISTICS_H
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class KthOrderStatistics
{
    public:
        KthOrderStatistics();
        ~KthOrderStatistics();

        int bruteforce(vector<int> v, int k);
        int orderselect(vector<int> v, int k);
        int kselect(vector<int> v, int k);
        int kheapsort(vector<int> v, int k);
        int heapselect(vector<int> v, int k);
        int quickselect(vector<int> v, int k);
        
    private:
        int partition(vector<int> &v, int start, int end);
        int pivot(vector<int> &v, int start, int end);
        bool isksmallest(vector<int> &v, int target, int k);
};

#endif