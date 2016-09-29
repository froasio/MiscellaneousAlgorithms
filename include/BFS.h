#ifndef BFS_H
#define BFS_H
#include "ShortestPath.h"
#include <queue>

class BFS : public ShortestPath
{
public:
	BFS(Digraph &g, int source, int destination);
	~BFS();
};

#endif