#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <iostream>

using namespace std;

class Digraph
{
    public:
        Digraph(int vv);
        ~Digraph();
        Digraph() = delete;
        int V();
        int E();

    private:

    const int v;
    int e;

};

#endif