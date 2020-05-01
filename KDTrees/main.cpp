/* main: Contains main function that completes all tasks required
 for program kd.
*/
#include "trees.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3)
    {
	cout << "Warning: need exactly two command line arguments." << endl;
	cout << "Usage: " << argv[0] << " parameter probe" << endl;
	return 1;
    }
    // Assign command line argument to iss variable
    istringstream iss(argv[1]);
    int param;
    istringstream iss2(argv[2]);
    int probe;
    
    // Check for valid input
    iss >> param;
    if (iss.fail())
    { 
	cout << "Invalid Input! Please enter an integer." << endl;  
    	return 1;
    }
    if (param < 0)
    {
	cout << "Tree requires 0 or more parameters." << endl;
	return 1;
    }
    iss2 >> probe;
    if (iss2.fail())
    { 
	cout << "Invalid Input! Please enter an integer." << endl;  
    	return 1;
    }
    if (probe < 0)
    {
	cout << "Tree requires 0 or more data points." << endl;
	return 1;
    }
    KDtree KD1;
    // Make an array of external nodes and determine max and min for each
    // dimension
    datapoint *elem = new datapoint[param];
    for(int i = 0; i < param; i++)
        elem[i].newData();
    // Make an array of probe nodes for later probing
    datapoint *probes = new datapoint[probe];
    for(int i = 0; i < probe; i++)
	probes[i].newData();
    int numprobes = probe;
    int size = param;
    // If we only need one bucket, create a single bucket
    if(size <= 10){
        node* leaf = new node;
	leaf->makeBucket(elem, size);  
	KD1.setRoot(leaf);		
    }
    else{
	// Set up initial internal node with both leaves
	node *internal = new node;
	node *leftBucket = new node;
	node *rightBucket = new node;
	internal->makeInternal(elem, size);
	KD1.setRoot(internal);
	leftBucket->leftBucket(elem, size, internal);
	rightBucket->rightBucket(elem, size, internal);	
	KD1.addLeaf(leftBucket, rightBucket, internal);
	// Recursively make new internal nodes and buckets
	// as necessary
	KD1.transform(leftBucket);
	KD1.transform(rightBucket);
    }
    // Dive for probe bucket and print
    for(int i = 0; i < numprobes; i++){
        probes[i].printProbe();
	KD1.probeDive(probes[i], numprobes);
    }	
}
