#include "Digraph.h"

Digraph::Digraph(int vv) : v(vv), e(0), adj(vv) {

}

Digraph::~Digraph(){
	
}

int Digraph::V(){
	return this->v;
}

int Digraph::E(){
	return this->e;
}

void Digraph::addEdge(int s, int d, int w) {
	Edge edge(s,d,w);
	adj[s].push_back(edge);
	this->e++;
}
