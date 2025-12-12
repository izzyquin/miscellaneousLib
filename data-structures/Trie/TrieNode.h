#ifndef TRIENODE_H
#define TRIENODE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>

#define ALPHABET_CHARS        26
#define MAX_WORD_LENGTH       100


class TrieNode {

private:
    struct Node {
        struct Node* children[ALPHABET_CHARS];
        bool isEndOfWord;
    };

    struct Node* root;

    struct Node* createNode() {
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));

        if (node == NULL)
        {
            return NULL;
        }    

        node->isEndOfWord = false;
        for(int i = 0; i < ALPHABET_CHARS; i++)
            node->children[i] = NULL;

        return node;
    }

public:
    TrieNode() {
        root = createNode();
    }

    void insert(const std::string& word);
    bool search(const std::string& word);
};


#endif /* TRIENODE_H */
