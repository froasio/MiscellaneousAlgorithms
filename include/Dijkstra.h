#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "ShortestPath.h"
#include <queue>
#include <utility>

class Dijkstra : public ShortestPath
{
public:
	Dijkstra(Digraph &g, int source);
	~Dijkstra();
};

#endif