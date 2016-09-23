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