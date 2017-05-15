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

void LinearSorting::dnfSort(vector<int> &v) {
	/*
		Lo := 1; Mid := 1; Hi := N;
		while Mid <= Hi do
			Invariant: a[1..Lo-1]=0 and a[Lo..Mid-1]=1 and a[Hi+1..N]=2; a[Mid..Hi] are unknown.
			case a[Mid] in
			0: swap a[Lo] and a[Mid]; Lo++; Mid++
			1: Mid++
			2: swap a[Mid] and a[Hi]; Hi--
	*/

	size_t low, mid, high;

	low = 0;
	mid = 0;
	high = v.size() - 1;

	while( mid <= high ) {

		if( v[mid] == 0 )
			swap(v[low++], v[mid++]);

		else if ( v[mid] == 1 )
			mid++;
		
		else 
			swap(v[high--], v[mid]);

	}
}
