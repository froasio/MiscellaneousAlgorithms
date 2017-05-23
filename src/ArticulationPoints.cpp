#include "ArticulationPoints.h"

ArticulationPoints::ArticulationPoints(Graph &g) :
	visited(g.V(), false), 
	parent(g.V(), -1),
	discoveryTimes(g.V(), 0),
	low(g.V(), 0),
	time(0) {

	g.iter([&](int v) {
		if(!this->isVisited(v))
			this->dfs(g, v);
	});


}

ArticulationPoints::~ArticulationPoints() {

}

void ArticulationPoints::dfs(Graph &g, int v) {

	size_t children = 0;
	
	this->setVisited(v);
	
	this->time++;

	this->discoveryTimes[v] = this->time;

	this->low[v] = this->time;

	g.adj(v, [&](Edge &edge){
		int adjVertex = edge.getDestination();
		
		if(!this->isVisited(adjVertex)) {
			children++;
			this->parent[adjVertex] = v;

			this->dfs(g, adjVertex);

			this->low[v] = min(low[v], low[adjVertex]);

			if(this->parent[v] == -1 and children > 1)
				this->articulationPoints.insert(v);

			if(this->parent[v] != -1 and this->low[adjVertex] >= this->discoveryTimes[v])
				this->articulationPoints.insert(v);
		}

		else if(adjVertex != this->parent[v])
			this->low[v] = min(this->low[v], this->discoveryTimes[adjVertex]);

	});

}

bool ArticulationPoints::isVisited(int v) {
	return this->visited[v];
}

void ArticulationPoints::setVisited(int v) {
	this->visited[v] = true;
}

vector<int> ArticulationPoints::getArticulationPoints(){
	vector<int> aps;
	std::copy(this->articulationPoints.begin(), this->articulationPoints.end(), std::back_inserter(aps));
	return aps;
}