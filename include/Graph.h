#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <functional>
#include "Edge.h"

using namespace std;

class Graph
{
    public:
        Graph(int vv);
        Graph(ifstream &ifs);
        ~Graph();
        Graph() = delete;
        int V();
        int E();
        virtual void addEdge(int s, int d, double w);
        void addEdge(Edge edge);
        void iterEdges(function<void(Edge&)> f);
        void adj(int u, function<void(Edge&)> f);
        void adjE(int u, function<void(Edge&)> f);
        void iter(function<void(int)> f);
        string toString();

    protected:

	    int v;
	    int e;
	    vector<list<Edge>> adj_e;

};

#endif