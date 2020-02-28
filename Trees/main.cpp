/* main: Contains main function that completes all tasks required
 for Trees assignment.
*/
#include "trees.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2)
    {
	cout << "Warning: need exactly one command line argument." << endl;
	cout << "Usage: " << argv[0] << " elements" << endl;
	return 1;
    }
    // Assign command line argument to iss variable
    istringstream iss(argv[1]);
    int elements;
    
    // Check for valid input
    iss >> elements;
    if (iss.fail())
    { 
	cout << "Invalid Input! Please enter an integer." << endl;  
    	return 1;
    }
    if (elements < 0)
    {
	cout << "Tree requires 0 or more data points." << endl;
	return 1;
    }
    tree T1, T2;
    int rand;
    for(int i = 0; i < elements; i++)
    {
	// Get data points from standard input and insert
	// into T1 sorted on the x value
	cin >> rand;
	int x = rand;
	cin >> rand;
	int y = rand;
	cin >> rand;
	int z = rand;
	T1.insertNode(x, y, z);
    }
    // Print T1 in symmetric order
    node *T1root = T1.getRoot();
    T1.printSymm(T1root);
    // Look through T1 in preorder and insert each value visited into T2
    // sorted on the y value
    T2.preTscribe(T1root);
    node *T2root = T2.getRoot();
    // Print T2 in postorder
    T2.printPostorder(T2root);
    cin >> rand;
    int probe = rand;
    node *hold = NULL;
    // Check that T2 isn't empty. If it is print "Tree is Empty"
    if(T2root != NULL)
        T2.search(T2root, hold, probe);
    else
	cout << "Tree is Empty" << endl;
	
    return 0;
}
