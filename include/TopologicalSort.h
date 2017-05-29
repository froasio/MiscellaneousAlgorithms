#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H
#include <vector>
#include <limits>
#include <deque>
#include "Digraph.h"
#include "Edge.h"

using namespace std;

class TopologicalSort
{
	public:
		TopologicalSort(Digraph &g);
		~TopologicalSort();
		vector<int> getTopolicalSort();
		bool getHasCycle();

	private:
		enum Color {WHITE, GREY, BLACK};
		vector<Color> visited;
		deque<int> s;
		bool hasCycle;
		TopologicalSort::Color getColor(int v);
		void setColor(int v, Color color);
		void tsort(Digraph &g, int v);
};

#endif