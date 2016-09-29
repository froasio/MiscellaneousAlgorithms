#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H
#include <list>
#include <vector>
#include <limits>
#include "Digraph.h"
#include "Edge.h"

using namespace std;

class ShortestPath
{
	public:
		ShortestPath(Digraph &g, int source, int destination);
		bool isVisited(int v);
		list<Edge> path(int v);
		string stringPath(int v);
		double distance(int v);
		~ShortestPath();

	protected:
		Edge edgeTo(int v);
		int src;
		int dst;
		vector<double> distances;
		vector<Edge> edges; 	
};

#endif