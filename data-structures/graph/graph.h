#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include "../lib/assert_lib.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;
class graph {
private:
    int _max_node_child;
    map<DataType, Node*> vertex_storage;

public:
    graph(int max_node_child = 2);
    
    ~graph();

    Node* find(DataType* key);

    Node* findNode(DataType* key, bool storeIfNotExist);

    void addEdge(DataType* src, DataType * dst);

    vector<DataType> DFS_traverse(DataType* src);

    vector<DataType> BFS_traverse(DataType* src);

    static void print(vector<DataType> vec);
};

#endif // QRAPH_H