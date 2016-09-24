#include "Edge.h"

Edge::Edge(int s, int d, int w) : source(s), destination(d), weight(w) {

}

Edge::Edge(): source(0), destination(0), weight(0) {
	
}

Edge::~Edge() {

} 

int Edge::getSource() {
	return this->source;
}

int Edge::getDestination() {
	return this->destination;
}

int Edge::getWeight() {
	return this->weight;
}

Edge Edge::make_edge(int s, int d, int w){
	Edge edge(s,d,w);
	return edge;
}