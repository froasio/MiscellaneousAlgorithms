#ifndef ARTICULATION_POINTS_H
#define ARTICULATION_POINTS_H
#include <list>
#include <vector>
#include <limits>
#include <set>
#include <stack>
#include "Graph.h"
#include "Edge.h"

using namespace std;

class ArticulationPoints
{
	public:
		ArticulationPoints(Graph &g);
		~ArticulationPoints();
		vector<int> getArticulationPoints();

	private:
		vector<bool> visited;
		set<int> articulationPoints;
		vector<int> parent;
		vector<int> discoveryTimes;
		vector<int> low;
		int time;
		bool isVisited(int v);
		void setVisited(int v);
		void dfs(Graph &g, int v);

};

#endif