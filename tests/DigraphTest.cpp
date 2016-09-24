#include "CppUTest/TestHarness.h"
#include "Digraph.h"

TEST_GROUP(digraphTest)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(digraphTest, testThatGraphReturnsVertexes)
{
	Digraph g(10);
	CHECK_EQUAL(10,g.V());
	CHECK_EQUAL(0,g.E());
}

TEST(digraphTest, testWhenAddEdgeEdgesIncrease)
{
	Digraph g(10);
	g.addEdge(1,2,3);
	CHECK_EQUAL(10,g.V());
	CHECK_EQUAL(1,g.E());
}

TEST(digraphTest, testGraphAllEdgesIteration){
	Digraph g(3);
	vector<Edge> v(3);
	v[0] = Edge::make_edge(1,2,0);
	v[1] = Edge::make_edge(0,1,1);
	v[2] = Edge::make_edge(0,2,2);

	for(Edge edge: v){
		g.addEdge(edge);
	}

	g.iterEdges([&](Edge& edge){
		CHECK_EQUAL(edge.getSource(), v[edge.getWeight()].getSource());
		CHECK_EQUAL(edge.getDestination(), v[edge.getWeight()].getDestination());
	});
}