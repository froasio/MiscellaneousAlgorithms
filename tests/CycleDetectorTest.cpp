#include "CppUTest/TestHarness.h"
#include <cmath>
#include "Graph.h"
#include "CycleDetector.h"

TEST_GROUP(CycleDetector)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(CycleDetector, testCycleDetectorHasCycle)
{
    
    ifstream input("tests/graph_G.txt");
    Graph g(input);

    CycleDetector cd(g);

    CHECK_TRUE(cd.getHasCycle());
}

TEST(CycleDetector, testCycleDetectorHasNoCycle)
{
    
    ifstream input("tests/graph_H.txt");
    Graph g(input);

    CycleDetector cd(g);

    CHECK_FALSE(cd.getHasCycle());
}