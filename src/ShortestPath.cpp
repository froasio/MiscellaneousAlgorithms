#include "ShortestPath.h"

ShortestPath::ShortestPath(Digraph &g, int origin):src(origin), distances(g.V()) {

}

bool ShortestPath::isVisited(int v){
	return this->distance(v) != numeric_limits<double>::infinity();
}

list<Edge> ShortestPath::path(int v) {
	list<Edge> l;
	Edge e(v,v,1.1);
	l.push_back(e);
	return l;
}
