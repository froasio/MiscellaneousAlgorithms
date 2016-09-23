#ifndef EDGE_H
#define EDGE_H

using namespace std;

class Edge
{
    public:
        Edge(int s, int d, int w);
        ~Edge();
        Edge() = delete;

        int getSource();
        int getDestination();
        int getWeight();

    private:
        const int source;
        const int destination;
        int weight;
};

#endif