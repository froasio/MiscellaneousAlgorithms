#include "CppUTest/TestHarness.h"
#include <cmath>
#include "Digraph.h"

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

}