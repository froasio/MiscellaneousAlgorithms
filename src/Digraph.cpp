#include "Digraph.h"
#include <sstream>

Digraph::Digraph(int vv) : v(vv), e(0), adj_e(vv), inc_e(vv) {

}

Digraph::Digraph(ifstream &ifs) {
	string line;
	int src, dst;
	double weight;

	int vv, ee;
	ifs >> vv >> ee;

	this->v = vv;
	this->e = 0;
	this->adj_e.resize(vv);
	this->inc_e.resize(vv);

	std::getline(ifs, line);

	for(int ei = 0; ei < ee; ei++){

		std::getline(ifs, line);
		std::istringstream linestream(line);
		linestream >> src >> dst;
		
		/*Allows to read graph weighted graphs*/
		weight = 0;
		if(linestream)
			linestream >> weight;
		
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
