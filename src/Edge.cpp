#include "Edge.h"

Edge::Edge(int s, int d, double w) : source(s), destination(d), weight(w) {

}

Edge::Edge(): source(0), destination(0), weight(0) {
	
}

Edge::~Edge() {

} 

int Edge::getSource() const{
	return this->source;
}

int Edge::getDestination() const{
	return this->destination;
}

double Edge::getWeight() const{
	return this->weight;
}

Edge Edge::make_edge(int s, int d, double w){
	Edge edge(s,d,w);
	return edge;
}

bool Edge::operator==(const Edge& re) const{
	return this->getSource() == re.getSource() and
		   this->getDestination() == re.getDestination() and 
		   this->getWeight() == re.getWeight();
}

bool Edge::operator!=(const Edge& re) const{
	return !(*this == re);
}

bool Edge::operator<(const Edge& re) const{
	return this->getWeight() < re.getWeight();
}

bool Edge::operator>(const Edge& re) const{
	return re < *this;
}

bool Edge::operator<=(const Edge& re) const{
	return !(*this > re);
}

bool Edge::operator>=(const Edge& re) const{
	return !(*this < re);
}

string Edge::toString() {
	stringstream ws;
	ws << fixed << setprecision(1) << this->getWeight();
	string es = to_string(this->getSource()) + " " + to_string(this->getDestination()) + " " + ws.str();
	return es;
}

string Edge::toStringPair() {
	return "(" + to_string(this->getSource()) + "," + to_string(this->getDestination()) + ")";
}