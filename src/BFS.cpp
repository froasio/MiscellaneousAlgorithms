#include "BFS.h"

BFS::BFS(Digraph &g, int source):
	ShortestPath(g,source){
	queue<int> q;
	int currentVertex;
	
	q.push(this->src);

	while(!q.empty()) {
		currentVertex = q.front();
		q.pop();
		g.adj(currentVertex, [&](Edge &edge){
			int adjVertex = edge.getDestination();
			if(!this->isVisited(adjVertex)) {
				q.push(adjVertex);
				this->edges[adjVertex] = edge;
				this->distances[adjVertex] = edge.getWeight();
			}
		});
	}
}

BFS::~BFS(){

}
