#include "CppUTest/TestHarness.h"
#include <cmath>
#include "Digraph.h"
#include "ArticulationPoints.h"

TEST_GROUP(articulationPointsTest)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(articulationPointsTest, testArticulationPointsAlgorithm)
{
    
    ifstream input("tests/graph_D.txt");
    Graph g(input);

    ArticulationPoints ap(g);

    vector<int> aps = ap.getArticulationPoints();
    vector<int> expectedAps = {2,3};

    for(size_t i = 0; i < aps.size(); i++) {
        CHECK_EQUAL(expectedAps[i], aps[i]);
    }
}