#include "KthOrderStatistics.h"


KthOrderStatistics::KthOrderStatistics()
{
  
}

KthOrderStatistics::~KthOrderStatistics()
{
  
}

int KthOrderStatistics::quickselect(vector<int> &v, int k)
{
    
    int pos = -1;
    int start = 0;
    int end = (int)v.size() - 1;
    
    while(pos != k){
        
        pos  = partition(v,start,end);
        if(pos > k){
            end = pos - 1;
        } else {
            start = pos + 1;
        }
    }
    return v[pos];
}

int KthOrderStatistics::kheapsort(vector<int> &v, int k){

    priority_queue< int, vector<int>, greater<int> > heap;
    for(int i : v){
        heap.push(i);
    }
    for(int j = 0; j < k; j++){
        heap.pop();
    }
    return heap.top();

}

int KthOrderStatistics::partition(vector<int> &v, int start, int end){

    int i_pivot = pivot(v,start,end);
    int pivot_v = v[i_pivot];

    swap(v[i_pivot],v[start]);

    int s = start + 1;
    int e = end;

    while(s <= e){
        while(s <= e and v[s] <= pivot_v) {
            s++;
        }
        while(s <= e and v[e] > pivot_v) {
            e--;
        }
        if(s < e){
            swap(v[s],v[e]);
        }
    }

    swap(v[s-1], v[start]);
    return s - 1;
}

int KthOrderStatistics::pivot(vector<int> &v, int start, int end){
    (void)v;
    (void)end;
    return start;
}