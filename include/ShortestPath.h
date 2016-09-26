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
		ShortestPath(Digraph &g, int origin);
		bool isVisited(int v);
		list<Edge> path(int v);
		virtual double distance(int v) = 0;
		~ShortestPath();

	protected:
		virtual Edge edgeTo(int v) = 0;

	private:
		int src;
		vector<double> distances;	
};

#endif