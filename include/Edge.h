#ifndef EDGE_H
#define EDGE_H

using namespace std;

class Edge
{
    public:
        Edge(int s, int d, int w);
        Edge();
        ~Edge();

        int getSource();
        int getDestination();
        int getWeight();

        static Edge make_edge(int s, int d, int w);

    private:
        int source;
        int destination;
        int weight;
};

#endif