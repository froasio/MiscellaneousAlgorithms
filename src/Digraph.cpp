#include "Digraph.h"

Digraph::Digraph(int vv) : v(vv), e(0){

}

Digraph::~Digraph(){
	
}

int Digraph::V(){
	return this->v;
}

int Digraph::E(){
	return this->e;
}