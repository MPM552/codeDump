// trees.h
// Header class for program trees. Includes a node class for elements of 
// the tree and a tree class for each tree root.

#include <iostream>
#include <sstream>
#include <climits>
using namespace std;

// node class to make node objects with data a left and right pointer
class node
{
    friend class tree;
    public:
	node();
	
    private:
    	int x, y, z;
	node *left;
	node *right;	

};
// tree class made of nodes with root value that point to tree strat
// contains functions used on T1 and T2 throughout main
class tree
{
    public:
	tree();
	node* getRoot();
	void setRoot(node *leaf);
	void insertNode(int x, int y, int z);
	void preTscribe(node *leaf);
	void printSymm(node *root);
	void printPostorder(node *root);
	void search(node *leaf, node *hold, int probe);

    private:
	node *root;
};
