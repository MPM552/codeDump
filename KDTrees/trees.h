/* Trees.h
 * Contains the declaration of the methods used in kd
 */
#include <iostream>
#include <sstream>
#include <climits>
#include <vector>

const int DIMENSIONS = 4;

using namespace std;

// Data class that holds all data points
class datapoint{
    friend class node;
    friend class KDtree;
    public:
	datapoint();
        void newData();
	void printProbe();
    private:
	int data[DIMENSIONS];
};

// Node class that acts as a leaf and internal node class
class node{
    friend class KDtree; 
    public:
	node();
	void makeBucket(datapoint points[], int size);
	void leftBucket(datapoint array[], int size, node* internal);
	void rightBucket(datapoint array[], int size, node* internal);
	void makeInternal(datapoint array[], int size);
	void printBucket(); 
    private:
	bool internal; // 0=leaf 1=internal node. Assume leaf.
	vector<datapoint> allpoints; 
	int value;
	int dim;
	node *left;
	node *right;
};

// Tree class 
class KDtree{
    public:
	KDtree();
	int quickselect(int dim, datapoint array[], int leftIndex, 
	int rightIndex, int medIndex);
	int partition(int dim, datapoint array[], int leftIndex, int rightIndex,
	int pivotIndex);
	node* initialInternal(node array[], int size);
	void setRoot(node* bucket);
	void addLeaf(node* leftleaf, node* rightleaf, node* parent);
	void transform(node* tform);
	void probeDive(datapoint probe, int numprobes);
    private:
	node *root;
		
};

