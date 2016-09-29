#include "CppUTest/TestHarness.h"
#include "BFS.h"

TEST_GROUP(shortestPathTest)
{

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(shortestPathTest, testBFSSourceEqualsDestinationReturnsEmptyPath)
{
	ifstream input("tests/graph_A.txt");
	Digraph g(input);
	int source = 0;
	int destination = 0;
	BFS bfs(g,source,destination);
	string egs = "";
	CHECK(egs == bfs.stringPath(destination));
}

TEST(shortestPathTest, testBFSShortestPath)
{
	ifstream input("tests/graph_A.txt");
	int source = 0;
	int destination = 3;
	
	Digraph g(input);
	cout<<g.toString()<<endl;
	BFS bfs(g,source,destination);
	string egs = "(0,5),(5,3)";
	CHECK(egs == bfs.stringPath(destination));

}
