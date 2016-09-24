#include "Digraph.h"

Digraph::Digraph(int vv) : v(vv), e(0), adj_e(vv), inc_e(vv) {

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
	adj_e[s].push_back(edge);
	inc_e[d].push_back(edge);
	this->e++;
}

void Digraph::addEdge(Edge edge){
	this->addEdge(edge.getSource(), edge.getDestination(), edge.getWeight());
}

void Digraph::iterEdges(function<void(Edge&)> f){

	for(list<Edge> &adj_e_v : adj_e){
		for(Edge &edge : adj_e_v){
			f(edge);
		}
	}

}

void Digraph::adj(int u, function<void(Edge&)> f) {
	for(Edge& edge : adj_e[u])
		f(edge);
}

void Digraph::adjE(int u, function<void(Edge&)> f) {
	for(Edge& edge : inc_e[u])
		f(edge);
}

void Digraph::iter(function<void(int)> f) {
	for(int u = 0; u < this->V(); u++)
		f(u);
}