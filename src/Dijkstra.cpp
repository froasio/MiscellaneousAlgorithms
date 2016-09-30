#include "Dijkstra.h"

Dijkstra::Dijkstra(Digraph &g, int source):
	ShortestPath(g,source){

	priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> minHeap;
    int currentVertex = this->src;

	minHeap.push(make_pair(currentVertex, this->src));

    while(!minHeap.empty()) {
    	currentVertex = minHeap.top().second;
    	minHeap.pop();

    	g.adj(currentVertex, [&](Edge &edge){
    		int adjVertex = edge.getDestination();
    		double weight = edge.getWeight();
    		if (this->distance(adjVertex) > this->distance(currentVertex) + weight)
            {
                this->distances[adjVertex] = this->distance(currentVertex) + weight;
                this->edges[adjVertex] = edge;
                minHeap.push(make_pair(this->distance(adjVertex), adjVertex));
            }
    	});

    }

}
Dijkstra::~Dijkstra(){

}