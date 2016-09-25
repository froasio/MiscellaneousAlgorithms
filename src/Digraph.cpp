#include "Digraph.h"

Digraph::Digraph(int vv) : v(vv), e(0), adj_e(vv), inc_e(vv) {

}

Digraph::Digraph(ifstream &ifs) {
	int vv, ee, src, dst;
	double weight;
	ifs >> vv >> ee;

	this->v = vv;
	
	this->adj_e.resize(vv);
	this->inc_e.resize(vv);

	for(int ei = 0; ei < ee; ei++){
		ifs >> src >> dst >> weight;
		this->addEdge(src, dst, weight);
	}

}

Digraph::~Digraph(){
	
}

int Digraph::V(){
	return this->v;
}

int Digraph::E(){
	return this->e;
}

void Digraph::addEdge(int s, int d, double w) {
	Edge edge(s,d,w);
	adj_e[s].push_back(edge);
	inc_e[d].push_back(edge);
	this->e++;
}

void Digraph::addEdge(Edge edge){
	this->addEdge(edge.getSource(), edge.getDestination(), edge.getWeight());
}

void Digraph::iterEdges(function<void(Edge&)> f){

	this->iter([&](int u){
		this->adj(u, f);
	});

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

string Digraph::toString() {
	string s;
	s = to_string(this->V()) + "\n";
	s+= to_string(this->E()) + "\n";
	this->iterEdges([&](Edge &edge){
		s+=edge.toString() + "\n";
	});
	return s;
}
