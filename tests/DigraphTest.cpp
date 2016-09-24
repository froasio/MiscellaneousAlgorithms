#include "CppUTest/TestHarness.h"
#include "Digraph.h"
#include <numeric> 

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
		CHECK(v[edge.getWeight()] == edge);
	});
}

TEST(digraphTest, testAdjacentEdgesIteration) {

	Digraph g(4);
	vector<Edge> v(4);

	v[0] = Edge::make_edge(0,0,0);
	v[1] = Edge::make_edge(0,1,1);
	v[2] = Edge::make_edge(0,2,2);
	v[3] = Edge::make_edge(0,3,3);

	for(Edge edge: v){
		g.addEdge(edge);
	}

	g.adj(0, [&](Edge& edge){
		CHECK(v[edge.getWeight()] == edge);
	});
}

TEST(digraphTest, testIterationOverVertexes) {
	Digraph g(5);
	vector<int> v(5);
	iota(v.begin(), v.end(), 0);
	g.iter([&](int w){ 
		CHECK(v[w] == w);
	});
}