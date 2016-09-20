#include "KthOrderStatistics.h"


KthOrderStatistics::KthOrderStatistics()
{
  
}

KthOrderStatistics::~KthOrderStatistics()
{
  
}

int KthOrderStatistics::bruteforce(vector<int> v, int k){
    int i;
    for(i = 0; i < (int)v.size(); i++){
        if(isksmallest(v,v[i],k)) break;
    }
    return v[i];
}

bool KthOrderStatistics::isksmallest(vector<int> &v, int target, int k){
    int count = 0;
    for(int i: v){
        if(target > i)
            count++;
    }
    return count == k;
}

int KthOrderStatistics::orderselect(vector<int> v, int k){

    sort(v.begin(), v.end());
    return v[k];

}

int KthOrderStatistics::kselect(vector<int> v, int k){

    for(int i = 0; i <=k; i++){
        int index_min = v[i];
        for(int j = i; j < (int)v.size(); j++){
            if(v[j] < v[index_min]){
                index_min = j;
            }
        }
        swap(v[i], v[index_min]);
    }
    return v[k];
}

int KthOrderStatistics::kheapsort(vector<int> v, int k){

    priority_queue< int, vector<int>, greater<int> > heap;
    for(int i : v){
        heap.push(i);
    }
    for(int j = 0; j < k; j++){
        heap.pop();
    }
    return heap.top();

}

int KthOrderStatistics::heapselect(vector<int> v, int k){
    priority_queue<int, vector<int>> heap;
    int i;

    for(i = 0; i <= k ; i++){
        heap.push(v[i]);
    }

    for(; i < (int)v.size(); i++){
        if(v[i] < heap.top()){
            heap.pop();
            heap.push(v[i]);
        }
    }
    return heap.top();
}

int KthOrderStatistics::quickselect(vector<int> v, int k)
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