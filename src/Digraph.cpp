#include "Digraph.h"

Digraph::Digraph(int vv) : v(vv), e(0), adj(vv), inc(vv) {

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
	inc[d].push_back(edge);
	this->e++;
}

void Digraph::addEdge(Edge edge){
	this->addEdge(edge.getSource(), edge.getDestination(), edge.getWeight());
}

void Digraph::iterEdges(function<void(Edge&)> f){

	for(list<Edge> &adj_v : adj){
		for(Edge &edge : adj_v){
			f(edge);
		}
	}

}