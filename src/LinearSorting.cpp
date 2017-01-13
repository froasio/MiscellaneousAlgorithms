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

	for(int x: v)
		count[x - min]++;

	for(int i = min, z = 0; i <= max; i++)
	{
	    while( count[i - min] > 0 )
	    {
			v[z++] = i;
			count[i - min]--;
	    }
	}

}

void LinearSorting::counting(string &s) {

	char d[256] = {};
	int z = 0;

	for(char c: s)
		d[(size_t)c]++;

	for(int i = 0; i < 256; i++)
		while(d[i]--)
			s[z++] = (char)i;

}
