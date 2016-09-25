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

TEST(digraphTest, testGraphSerialization){
	Digraph g(3);
	g.addEdge(0,1,1.1);
	g.addEdge(0,2,2.2);
	g.addEdge(1,2,3.3);
	g.addEdge(2,0,1.4);

	string egs = "3\n4\n0 1 1.1\n0 2 2.2\n1 2 3.3\n2 0 1.4\n";
	string gs = g.toString();
	CHECK(egs == gs);
}