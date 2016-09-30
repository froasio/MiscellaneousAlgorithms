#include "ShortestPath.h"

ShortestPath::ShortestPath(Digraph &g, int source)
	:src(source),
	 distances(g.V(), numeric_limits<double>::infinity()),
	 edges(g.V()) {
	 	this->distances[source] = 0;
}

ShortestPath::~ShortestPath(){
	
}

bool ShortestPath::isVisited(int v) {
	return this->distance(v) != numeric_limits<double>::infinity();
}

double ShortestPath::distance(int v) {
	return this->distances[v];
}

Edge ShortestPath::edgeTo(int v) {
	return this->edges[v];
}

list<Edge> ShortestPath::path(int v) {
	list<Edge> le;
	int currentVertex = v;
	Edge edge;

	while(currentVertex != this->src){
		if(this->distance(currentVertex) == numeric_limits<double>::infinity()){
			le.clear();
			break;
		}
		edge = this->edgeTo(currentVertex);
		le.push_front(edge);
		currentVertex = edge.getSource();
	}

	return le;
}

string ShortestPath::stringPath(int v){
	list<Edge> p = this->path(v);
	string sp = "";
	for(Edge &edge : p){
		sp += edge.toStringPair() + ",";
	}
	if(sp.length()) sp.pop_back();
	return sp;
}
