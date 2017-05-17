#include "Kosaraju.h"

Kosaraju::Kosaraju(Digraph &g)
	: visited(g.V(), false) {

	stack<int> s;
	g.iter([&](int v){
		this->forwardDFS(g, v, s);
	});

	this->resetVisited();

	while(!s.empty()) {
		int v = s.top();
		s.pop();
		if(!this->isVisited(v)) {
			
			vector<int> components;
			this->backwardDFS(g, v, components);
			this->SCCs.push_back(components);

		}
	}

}

Kosaraju::~Kosaraju(){
	
}

bool Kosaraju::isVisited(int v) {
	return this->visited[v];
}

void Kosaraju::setVisited(int v) {
	this->visited[v] = true;
}

void Kosaraju::resetVisited() {
	std::fill(this->visited.begin(), this->visited.end(), false);
}

void Kosaraju::forwardDFS(Digraph &g, int v, stack<int> &s) {

	if(this->isVisited(v)){
		return;
	}

	this->setVisited(v);

	g.adj(v, [&](Edge &edge){
		int adjVertex = edge.getDestination();
		if(!this->isVisited(adjVertex)) {
			this->forwardDFS(g, adjVertex, s);
		}
	});

	s.push(v);

}

void Kosaraju::backwardDFS(Digraph &g, int v, vector<int> &components) {

	if(this->isVisited(v))
		return;

	this->setVisited(v);
	components.push_back(v);

	g.adjE(v, [&](Edge &edge){
		int adjVertex = edge.getSource();
		if(!this->isVisited(adjVertex)) {
			this->backwardDFS(g, adjVertex, components);
		}
	});

}

size_t Kosaraju::getSCCNumber() {

	return this->SCCs.size();

}

vector<int> Kosaraju::getMembersOfSCC(size_t sccId) {

	return this->SCCs[sccId];

}