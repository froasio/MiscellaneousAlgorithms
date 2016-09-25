#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "Edge.h"

using namespace std;

class Digraph
{
    public:
        Digraph(int vv);
        Digraph(ifstream &ifs)
        ~Digraph();
        Digraph() = delete;
        int V();
        int E();
        void addEdge(int s, int d, double w);
        void addEdge(Edge edge);
        void iterEdges(function<void(Edge&)> f);
        void adj(int u, function<void(Edge&)> f);
        void adjE(int u, function<void(Edge&)> f);
        void iter(function<void(int)> f);
        string toString();

    private:

	    int v;
	    int e;
	    vector<list<Edge>> adj_e;
	    vector<list<Edge>> inc_e;

};

#endif