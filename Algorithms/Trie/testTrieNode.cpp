/*  test functions to test the TrieNode methods

    You can run the method using the command below:
        g++ -std=c++14 -o main testTrieNode.cpp TrieNode.cpp -lgtest -lgtest_main -pthread
*/

#include "TrieNode.h"

#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class TrieTest: public ::testing::Test {
protected:
    
    TrieNode* n;

    void SetUp() override{
        n = new TrieNode();
    }

    void TearDown() override{
        delete n;
    }
};

TEST_F(TrieTest, BASIC_1) {
    n->insert("apple");
    EXPECT_EQ(n->search(" "), false);
    EXPECT_EQ(n->search("apple"), true);
    EXPECT_EQ(n->search("orange"), false);
}

TEST_F(TrieTest, BASIC_2) {
    n->insert("banana");
    EXPECT_EQ(n->search(" "), false);
    EXPECT_EQ(n->search("banana"), true);
    EXPECT_EQ(n->search("ban"), false);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

