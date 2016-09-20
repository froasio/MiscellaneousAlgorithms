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

        int orderselect(vector<int> v, int k);
        int kheapsort(vector<int> v, int k);
        int quickselect(vector<int> v, int k);
        
    private:
        int partition(vector<int> &v, int start, int end);
        int pivot(vector<int> &v, int start, int end);
};

#endif