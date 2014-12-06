#include <string>
#include <vector>
#include <iostream>

#define ALPHABET_SIZE 26

using namespace std;


class Node
{
public:
	bool is_end;
	bool visited;
	int prefix_count;
	int children_quantity;

	Node* children[ALPHABET_SIZE];
	Node* parent;

	string STR;
    Node(Node* pParent)
	{
		STR = "";

		prefix_count = 0;
		children_quantity=0;

		for (int i=0; i<ALPHABET_SIZE; i++)	*(children+i) = NULL;
		parent=pParent;
 		if (parent)
			pParent->children_quantity++;

		is_end = false;
		visited = false;
	}
};



class Trie
{
public:
    Trie()
	{
		root = new Node(NULL);
	}
	~Trie(){}
    void Insert(string);
    bool Search(string);
	Node* searchPrefix(string);
	int countPrefix(string);
    Node* root;
};

void Trie::Insert(string word)
{
    Node* current = root;

	current->prefix_count++;

    for (unsigned int i = 0; i < word.length(); i++ )
    {
		int letter_pos = word[i]-'A';

		if (current->children[letter_pos]==NULL)
			current->children[letter_pos] = new Node(current);


		current = current->children[letter_pos];
		current->prefix_count++;
		current->STR = word.substr(0, i+1);
    }
	current->is_end=true;
}


bool Trie::Search(string word)
{
    Node* current = root;
	
	for (unsigned int i = 0; i < word.length(); i++ )
	{
		if (current->children[word[i]-'a']==NULL)
			return false;

        current = current->children[word[i]-'a'];
	}
	return current->is_end;
}


Node* Trie::searchPrefix(string prefix)
{
    Node* current = root;
	
	for ( int i = 0; i < prefix.length(); i++ )
	{
		if (current->children[prefix[i]-'a']==NULL)
			return NULL;

        current = current->children[prefix[i]-'a'];
	}
	return current;
}


int Trie::countPrefix(string prefix)
{
    Node* prefix_node = searchPrefix(prefix);

	if (prefix_node!=NULL)
		return prefix_node->prefix_count;
	return -1;
}