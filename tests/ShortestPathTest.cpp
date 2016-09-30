#include "CppUTest/TestHarness.h"
#include <cmath>
#include "BFS.h"
#include "Dijkstra.h"

TEST_GROUP(shortestPathTest)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(shortestPathTest, testBFSShortestPath)
{
	
	ifstream input("tests/graph_A.txt");
	Digraph g(input);
	int source = 0;
	BFS bfs(g,source);
	string egs = "";
	CHECK(egs == bfs.stringPath(0));

	egs = "";
	CHECK(egs == bfs.stringPath(1));

	egs = "(0,5)";
	CHECK(egs == bfs.stringPath(5));

	egs = "(0,2),(2,3),(3,4)";
	CHECK(egs == bfs.stringPath(4));

}

TEST(shortestPathTest, testDijkstraShortestPath)
{
	
	ifstream input("tests/graph_B.txt");
	Digraph g(input);
	int source = 0;
	Dijkstra dikjstra(g,source);
	string egs = "";
	CHECK(egs == dikjstra.stringPath(0));

	egs = "(0,4),(4,5),(5,1)";
	CHECK(egs == dikjstra.stringPath(1));
	CHECK(abs(1.05 - dikjstra.distance(1)) < 1E-5);

	egs = "(0,2),(2,7),(7,3)";
	CHECK(egs == dikjstra.stringPath(3));
	CHECK(abs(0.99 - dikjstra.distance(3)) < 1E-5);	

}