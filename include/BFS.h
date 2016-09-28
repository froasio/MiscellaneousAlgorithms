#ifndef BFS_H
#define BFS_H
#include "ShortestPath.h"
#include <queue>

class BFS : public ShortestPath
{
public:
	void run(Digraph &g);
};

#endif