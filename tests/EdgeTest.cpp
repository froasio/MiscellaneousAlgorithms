#include "CppUTest/TestHarness.h"
#include "Edge.h"

TEST_GROUP(edgeTest)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(edgeTest, testEdgeInstanceWorks)
{
	Edge e(1,2,3);
	CHECK_EQUAL(1,e.getSource());
	CHECK_EQUAL(2,e.getDestination());
	CHECK_EQUAL(3,e.getWeight());	
}

TEST(edgeTest, testMakeEdgeReturnsEdge)
{
	Edge e = Edge::make_edge(1,2,3);
	CHECK_EQUAL(1,e.getSource());
	CHECK_EQUAL(2,e.getDestination());
	CHECK_EQUAL(3,e.getWeight());
}