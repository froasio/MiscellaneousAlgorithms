#ifndef EDGE_H
#define EDGE_H
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Edge
{
    public:
        Edge(int s, int d, double w);
        Edge();
        ~Edge();

        int getSource() const;
        int getDestination() const;
        double getWeight() const;
        bool operator==(const Edge& re) const;
        bool operator!=(const Edge& re) const;
        bool operator<(const Edge& re) const; 
        bool operator>(const Edge& re) const;
        bool operator<=(const Edge& re) const;
        bool operator>=(const Edge& re) const;
        string toString();

        static Edge make_edge(int s, int d, double w);

    private:
        int source;
        int destination;
        double weight;
};

#endif