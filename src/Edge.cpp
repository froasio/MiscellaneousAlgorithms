#include "Edge.h"

Edge::Edge(int s, int d, int w) : source(s), destination(d), weight(w) {

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