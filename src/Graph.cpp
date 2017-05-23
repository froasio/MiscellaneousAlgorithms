#include "Graph.h"
#include <sstream>

Graph::Graph(int vv) : v(vv), e(0), adj_e(vv) {

}

Graph::Graph(ifstream &ifs) {
	string line;
	int src, dst;
	double weight;

	int vv, ee;
	ifs >> vv >> ee;

	this->v = vv;
	this->e = 0;
	this->adj_e.resize(vv);

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

Graph::~Graph(){
	
}

int Graph::V(){
	return this->v;
}

int Graph::E(){
	return this->e;
}

void Graph::addEdge(int s, int d, double w) {
	Edge forward(s,d,w);
	Edge backward(d,s,w);

	adj_e[s].push_back(forward);
	adj_e[d].push_back(backward);
	this->e+=2;
}

void Graph::addEdge(Edge edge){
	this->addEdge(edge.getSource(), edge.getDestination(), edge.getWeight());
}

void Graph::iterEdges(function<void(Edge&)> f){

	this->iter([&](int u){
		this->adj(u, f);
	});

}

void Graph::adj(int u, function<void(Edge&)> f) {
	for(Edge& edge : adj_e[u])
		f(edge);
}

void Graph::adjE(int u, function<void(Edge&)> f) {
	for(Edge& edge : adj_e[u])
		f(edge);
}

void Graph::iter(function<void(int)> f) {
	for(int u = 0; u < this->V(); u++)
		f(u);
}

string Graph::toString() {
	string s;
	s = to_string(this->V()) + "\n";
	s+= to_string(this->E()) + "\n";
	this->iterEdges([&](Edge &edge){
		s+=edge.toString() + "\n";
	});
	return s;
}
