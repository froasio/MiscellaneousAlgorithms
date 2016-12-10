#include "LinearSorting.h"

void LinearSorting::counting(vector<int> &v) {

	if(v.size() == 0)
		return;

	int max, min;

	max = min = v[0];

	for(int x: v){
		max = x > max ? x : max;
		min = x < min ? x : min;
	}

	int buckets = max - min + 1;
	vector<int> count(buckets, 0);
	vector<int> output(v.size(),0);

	for(int x: v)
		count[x - min]++;

	for(int i = 1; i < buckets; i++)
		count[i] += count[i-1];

	for(int i = (int)v.size() - 1; i >= 0 ; i--){
		output[count[v[i]-min]-1] = v[i];
		count[v[i]-min]--;
	}

	for(int i = 0; i < (int)v.size(); i++)
		v[i] = output[i];

}