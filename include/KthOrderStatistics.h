#ifndef KTH_ORDER_STATISTICS_H
#define KTH_ORDER_STATISTICS_H
#include <vector>
#include <iostream>

using namespace std;

class KthOrderStatistics
{
    public:
        KthOrderStatistics();
        ~KthOrderStatistics();

        int quickselect(vector<int> &v, int k);
    
    private:
        int partition(vector<int> &v, int start, int end);
        int pivot(vector<int> &v, int start, int end);
};

#endif