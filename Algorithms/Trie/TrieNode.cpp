
#include <stdbool.h>
#include <string.h>
#include "TrieNode.h"

#define ALPHABET_CHARS		26
#define MAX_WORD_LENGTH 	100


void TrieNode::insert(const std::string& word){

	if (!word.length() || word.length() >= MAX_WORD_LENGTH)
		return;

	if (!root)
		root = createNode();

	struct Node* current = root;

	for (int i=0; word[i]!= '\0'; i++)
	{
		int index = word[i] - 'a';
		if (current->children[index] == NULL)
		{
			current->children[index] = createNode();
		}
		current=current->children[index];
	}
	current->isEndOfWord = true;
}

bool TrieNode::search(const std::string& word){
	if (root == NULL)
		return false;

	if (!word.length() || word.length() >= MAX_WORD_LENGTH)
		return false;

	struct Node* current = root;

	for (int i=0; word[i]!= '\0'; i++)
	{
		int index = word[i] - 'a';
		if (current->children[index] == NULL)
		{
			return false;
		}
		current=current->children[index];
	}
	
	return (current != NULL && current->isEndOfWord == true);
}

