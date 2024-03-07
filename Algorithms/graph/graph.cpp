#include <map>
#include "../lib/assert_lib.h"
#include "Stack.h"

using namespace std;
class graph {
private:
    int _max_node_child;
    map<DataType, Node*> vertex_storage;

public:
    graph(int max_node_child = 2): _max_node_child(max_node_child) {}


    Node* find(DataType* key){
        auto it = vertex_storage.find(*key);
        if (it != vertex_storage.end())
        {
            return it->second;
        }
        return nullptr;
    }

    Node* findNode(DataType* key, bool storeIfNotExist) {
        auto it = vertex_storage.find(*key);
        Node* node = nullptr;
        if (it == vertex_storage.end() && storeIfNotExist)
        {
            node = new Node(key);
            vertex_storage.insert(std::make_pair(*key, node));
        }
        else
        {
            node = it->second;
        }
        return node;
    }

    void addEdge(DataType* src, DataType * dst) {
        ASSERT(src != nullptr);
        ASSERT(dst != nullptr);

        Node* src_node = findNode(src, true);
        Node* dst_node = findNode(dst, true);

        src_node->addChild(dst_node); 
    }

    void DFS_traverse(DataType* src)
    {
        Node* src_node = findNode(src, false);
        ASSERT(src_node != nullptr);

        std::cout<<"DFS In progress"<<endl;
        // reset visited vertices throughout the graph
        for (auto i = vertex_storage.begin(); i != vertex_storage.end(); i++) {
            i->second->setVisited(false);
        }

        Stack* st = new Stack(10);

        src_node->setVisited(true);
        st->push(src_node);
        bool first_node_print = true;
        while(!st->isEmpty())
        {
            Node* curr = st->pop();
            if (curr == nullptr) {
                continue;
            }
            
            curr->setVisited(true);
            if (first_node_print)
            {
                std::cout<<curr->getData();
                first_node_print = false;
            }
            else
            {
                std::cout<<","<<curr->getData();
            }
            
            for (int i = 0; i < curr->getNumberOfChild(); i++)
            {
                int idx = curr->getNumberOfChild() - i - 1;
                Node* child = curr->childList[idx];
                if (!child->isVisited())
                {
                    st->push(curr->childList[idx]);
                }
            }
        }
        std::cout<<endl;
    }

    ~graph(){
        std::cout<<"Destroying nodes"<<endl;
        for (auto i = vertex_storage.begin(); i != vertex_storage.end(); i++) {
            delete i->second;
        }
    }

};


int main()
{
    graph g;
    DataType d0(0);
    DataType d1(1);
    DataType d2(2);
    DataType d3(3);
    DataType d4(4);
    DataType d5(5);
    DataType d6(6);

    // Add edges to the graph
    g.addEdge(&d0, &d1);        
    g.addEdge(&d0, &d2);
    g.addEdge(&d1, &d3);
    g.addEdge(&d1, &d4);
    g.addEdge(&d2, &d4);
    g.addEdge(&d3, &d5);
    g.addEdge(&d4, &d5);

    g.DFS_traverse(&d0);

    g.addEdge(&d4, &d6);
    g.DFS_traverse(&d0);

    return 0;
}

