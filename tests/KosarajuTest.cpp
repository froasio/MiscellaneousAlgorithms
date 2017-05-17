#include "CppUTest/TestHarness.h"
#include <cmath>
#include "Digraph.h"
#include "Kosaraju.h"

TEST_GROUP(tarjanTest)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(tarjanTest, testTarjanAlgorithm)
{
    
    ifstream input("tests/graph_C.txt");
    Digraph g(input);

    Kosaraju kosaraju(g);

    CHECK_EQUAL(3, kosaraju.getSCCNumber());
    vector<vector<int>> expectedScc= {{0,1,2},{3},{4}};
    
    for(size_t i = 0; i < kosaraju.getSCCNumber(); i++) {
        vector<int> scc = kosaraju.getMembersOfSCC(i);
        for(size_t j = 0; j < scc.size(); j++)
            CHECK_EQUAL(expectedScc[i][j], scc[j]);
    }
}