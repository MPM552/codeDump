// trees.cpp
// Defines functions declared in trees.h and provides a description of each

#include "trees.h"

using namespace std;

// Node constructor
node::node()
{
    left = NULL;
    right = NULL;
    x = 0;
    y = 0;
    z = 0;
} //node()
// Tree constructor
tree::tree()
{
    root = new node;
    root->x = INT_MIN;
    root->y = INT_MIN;
    root->z = INT_MIN;
} //tree()
// Get private root
node* tree::getRoot()
{
    return root->right;
} //getRoot()

// Based off in class notes combining makeNode and insertTree
void tree::insertNode(int x, int y, int z)
{
    // Declare nodes and pass data to leaf
    node *temp = root;
    node *parent = NULL;
    node *leaf = new node;
    leaf->x = x;
    leaf->y = y;
    leaf->z = z;
    // Dive through tree to find proper location for the new element
    while(temp != NULL){
    	parent = temp;
	if(x <= temp->x) 
	    temp = temp->left;
	else
	    temp = temp->right;
    }
    if (x <= parent->x)
	parent->left = leaf;
    else
	parent->right = leaf;
} // insertNode()

// Traverses a tree in preorder and adds each point visited to a new
// tree sorted on the element's y value
void tree::preTscribe(node *leaf)
{
    if (leaf != NULL){
	// Declare nodes and pass data to element for new tree from the 
	// current element of the completed tree.
        node *temp = root;
       	node *parent = NULL;
	node *T2leaf = new node;
    	T2leaf->x = leaf->x;
    	T2leaf->y = leaf->y;
    	T2leaf->z = leaf->z;
	// Dive down new tree for correct spot based on y value
	while(temp != NULL){
	    parent = temp;
    	    if(T2leaf->y <= temp->y) 
		temp = temp->left;
	    else
		temp = temp->right;
	}
    	if (T2leaf->y <= parent->y)
	    parent->left = T2leaf;
 	else
	    parent->right = T2leaf;
        
    	preTscribe(leaf->left);
    	preTscribe(leaf->right);
    } 
} // preTscribe()

// Print tree in postorder
// Each visited node is printed
void tree::printPostorder(node *dive)
{
    if(dive != NULL){
	printPostorder(dive->left);
	printPostorder(dive->right);
	cout << "(" << dive->x << ", ";
	cout << dive->y << ", ";
	cout << dive->z << ")" << endl;
    }
} //printPostorder()

// Print tree in symmetric order
void tree::printSymm(node *dive)
{
    if(dive != NULL){
	printSymm(dive->left);
	cout << "(" << dive->x << ", ";
    	cout << dive->y << ", ";
    	cout << dive->z << ")" << endl;
    	printSymm(dive->right);
    }
} // printSymm()

// Search for a specific point based on the y value. 
// If the point does not exist within the tree, the 
// last point visited is printed.
void tree::search(node *leaf, node *last, int probe)
{
    if(leaf == NULL){
	cout << "(" << last->x << ", ";
	cout << last->y << ", ";
	cout << last->z << ")" << endl;
    
    }
    else if(leaf->y == probe){
	cout << "(" << leaf->x << ", ";
	cout << leaf->y << ", ";
	cout << leaf->z << ")" << endl;
    }
    else if (probe < leaf->y)
    {
	last = leaf;
	search(leaf->left, last, probe);
    }
    else
    {
	last = leaf;
	search(leaf->right, last, probe);
    }
} // search()
