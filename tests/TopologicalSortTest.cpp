#include "CppUTest/TestHarness.h"
#include <cmath>
#include "Digraph.h"
#include "TopologicalSort.h"

TEST_GROUP(topologicalSort)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(topologicalSort, testTopologicalSortAlgorithm)
{
    
    ifstream input("tests/graph_E.txt");
    Digraph g(input);

    TopologicalSort topologicalSort(g);
    vector<int> topologicalSortedVertexes = topologicalSort.getTopolicalSort();
    vector<int> expectedTopologicalSortedVertexes = {8,5,6,7,4,0,2,1,3};
    for(size_t i = 0; i < topologicalSortedVertexes.size(); i++) {
            CHECK_EQUAL(expectedTopologicalSortedVertexes[i], topologicalSortedVertexes[i]);
    }
}

TEST(topologicalSort, testTopologicalSortAlgorithmWithCycle)
{
    
    ifstream input("tests/graph_F.txt");
    Digraph g(input);

    TopologicalSort topologicalSort(g);
    CHECK_TRUE(topologicalSort.getHasCycle()); 
}