#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H
#include <vector>
#include <limits>
#include <deque>
#include "Digraph.h"
#include "Graph.h"
#include "Edge.h"

using namespace std;

class CycleDetector
{
	public:
		CycleDetector(Graph &g);
		~CycleDetector();
		bool getHasCycle();

	private:
		vector<bool> visited;
		vector<int> parent;
		deque<int> queue;
		bool hasCycle;
		bool isVisited(int v);
		void setVisited(int v);
		void bfs(Graph &g, int v);
};

#endif