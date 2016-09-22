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

}