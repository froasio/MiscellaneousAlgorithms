#include "Graph.h"
#include "Digraph.h"

void Graph::addEdge(int s, int d, double w) {
	Digraph::addEdge(s,d,w);
	Digraph::addEdge(d,s,w);
}