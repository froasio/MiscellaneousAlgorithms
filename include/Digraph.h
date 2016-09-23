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

    private:

    const int v;
    int e;
    vector<list<Edge>> adj;

};

#endif