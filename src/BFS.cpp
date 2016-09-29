#include "BFS.h"

BFS::BFS(Digraph &g, int source, int destination):
	ShortestPath(g,source,destination){
	queue<int> q;
	int current_vertex;
	
	q.push(this->src);

	while(!q.empty()) {
		current_vertex = q.front();
		q.pop();
		if(current_vertex == this->dst) break;
		g.adj(current_vertex, [&](Edge &edge){
			int adjVertex = edge.getDestination();
			if(!this->isVisited(adjVertex)) {
				q.push(adjVertex);
				this->edges[adjVertex] = edge;
				this->distances[adjVertex] = edge.getWeight();
			}
		});
	}
}