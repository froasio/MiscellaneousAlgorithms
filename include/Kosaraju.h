#ifndef KOSARAJU_H
#define KOSARAJU_H
#include <list>
#include <vector>
#include <limits>
#include <stack>
#include "Digraph.h"
#include "Edge.h"

using namespace std;

class Kosaraju
{
	public:
		Kosaraju(Digraph &g);
		~Kosaraju();
		size_t getSCCNumber();
		vector<int> getMembersOfSCC(size_t sccId);

	private:
		vector<bool> visited;
		vector<vector<int>> SCCs;
		bool isVisited(int v);
		void setVisited(int v);
		void resetVisited();
		void forwardDFS(Digraph &g, int v, stack<int> &s);
		void backwardDFS(Digraph &g, int v, vector<int> &components);
};

#endif