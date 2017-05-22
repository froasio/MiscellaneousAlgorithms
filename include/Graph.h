#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <functional>
#include "Digraph.h"
#include "Edge.h"

using namespace std;

class Graph : public Digraph {
    public:
        void addEdge(int s, int d, double w);

};

#endif