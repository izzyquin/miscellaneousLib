/*  test functions to test the TrieNode methods

    You can run the method using the command below:
        g++ -std=c++14 -o main testTrieNode.cpp TrieNode.cpp -lgtest -lgtest_main -pthread
*/

#include "graph.h"

#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class GraphTest: public ::testing::Test {
protected:
    
    graph* g;
    DataType *d0, *d1, *d2, *d3, *d4, *d5, *d6;

    void SetUp() override{
        g = new graph();
        d0 = new DataType(0);
        d1 = new DataType(1);
        d2 = new DataType(2);
        d3 = new DataType(3);
        d4 = new DataType(4);
        d5 = new DataType(5);
        d6 = new DataType(6);
    }

    void TearDown() override{
        delete g;
    }
};

TEST_F(GraphTest, DFS_1) {
    // Add edges to the graph
    g->addEdge(d0, d1);        
    g->addEdge(d0, d2);
    g->addEdge(d1, d3);
    g->addEdge(d1, d4);
    g->addEdge(d2, d4);
    g->addEdge(d3, d5);
    g->addEdge(d4, d5);

    vector<DataType> dfs = g->DFS_traverse(d0);
    vector<DataType> exp= {DataType(0),DataType(1),DataType(3),DataType(5),DataType(4),DataType(2)};

    EXPECT_EQ(dfs.size(), 6);
    EXPECT_EQ(dfs, exp);
}

TEST_F(GraphTest, DFS_2) {
    g->addEdge(d0, d1);        
    g->addEdge(d0, d2);
    g->addEdge(d1, d3);
    g->addEdge(d1, d4);
    g->addEdge(d2, d4);
    g->addEdge(d3, d5);
    g->addEdge(d4, d5);
    g->addEdge(d4, d6);

    vector<DataType> dfs = g->DFS_traverse(d0);
    vector<DataType> exp= {DataType(0),DataType(1),DataType(3),DataType(5),DataType(4),DataType(6),DataType(2)};

    EXPECT_EQ(dfs.size(), 7);
    EXPECT_EQ(dfs, exp);
}

TEST_F(GraphTest, BFS_1) {
    g->addEdge(d0, d1);        
    g->addEdge(d0, d2);
    g->addEdge(d1, d3);
    g->addEdge(d1, d4);
    g->addEdge(d2, d4);
    g->addEdge(d3, d5);
    g->addEdge(d4, d5);
    
    vector<DataType> bfs = g->BFS_traverse(d0);
    vector<DataType> exp= {DataType(0),DataType(1),DataType(2),DataType(3),DataType(4),DataType(5)};

    EXPECT_EQ(bfs.size(), 6);
    EXPECT_EQ(bfs, exp);
}

TEST_F(GraphTest, BFS_2) {
    g->addEdge(d0, d1);        
    g->addEdge(d0, d2);
    g->addEdge(d1, d3);
    g->addEdge(d1, d4);
    g->addEdge(d2, d4);
    g->addEdge(d3, d5);
    g->addEdge(d4, d5);
    g->addEdge(d4, d6);

    vector<DataType> bfs = g->BFS_traverse(d0);
    vector<DataType> exp= {DataType(0),DataType(1),DataType(2),DataType(3),DataType(4),DataType(5),DataType(6)};

    EXPECT_EQ(bfs.size(), 7);
    EXPECT_EQ(bfs, exp);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}