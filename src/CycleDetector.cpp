#include "CycleDetector.h"

CycleDetector::CycleDetector(Graph &g) :
	visited(g.V(), false),
	parent(g.V(), -1),
	hasCycle(false) {

	g.iter([&](int v) {
		if(!this->isVisited(v) and this->getHasCycle() == false)
			this->bfs(g, v);
	});

}

CycleDetector::~CycleDetector() {

}

bool CycleDetector::getHasCycle() {
	return this->hasCycle;
}

bool CycleDetector::isVisited(int v) {
	return this->visited[v];
}

void CycleDetector::setVisited(int v) {
	this->visited[v] = true;
}

void CycleDetector::bfs(Graph &g, int root) {

	this->queue.push_front(root);

	while(!this->queue.empty()) {
		
		int next = this->queue.back();
		this->queue.pop_back();

		if(this->isVisited(next)) {
			this->hasCycle = true;
			return;
		}

		this->setVisited(next);

		g.adj(next, [&](Edge &edge) {
			
			int adjVertex = edge.getDestination();
			this->parent[adjVertex] = next;

			if(this->parent[next] != adjVertex) {
				this->queue.push_front(adjVertex);
			}

		});

	}

}