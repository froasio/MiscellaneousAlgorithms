#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <iostream>
#include <vector>
#include <list>
#include "Edge.h"

using namespace std;

class Digraph
{
    public:
        Digraph(int vv);
        ~Digraph();
        Digraph() = delete;
        int V();
        int E();
        void addEdge(int s, int d, int w);
        void addEdge(Edge edge);
        void iterEdges(function<void(Edge&)> f);
        void adj(int u, function<void(Edge&)> f);
        void adjE(int u, function<void(Edge&)> f);
        void iter(function<void(int)> f);

    private:

	    const int v;
	    int e;
	    vector<list<Edge>> adj_e;
	    vector<list<Edge>> inc_e;

};

#endif