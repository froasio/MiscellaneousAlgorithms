#ifndef LINEAR_SORTING_H
#define LINEAR_SORTING_H
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class LinearSorting
{
    public:
        LinearSorting(){};
        ~LinearSorting(){};

        void counting(vector<int> &v);
        void counting(string &s);
        void dnfSort(vector<int> &v);
        
};

#endif