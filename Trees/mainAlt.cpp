/* mainAlt: make treesAlt
*/
#include "trees.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc !=2)
    {
	cout << "Warning: need exactly one command line arguments." << endl;
	cout << "Usage: " << argv[0] << " elements" << endl;
	return 1;
    }
    // Assign iss variable to command line argument
    istringstream iss( argv[1] );
    int elements;
    
    // Check for valid input
    if (iss >> elements)
	cout << "Elements: " << elements << endl;
    else 
    {
	cout << "Invalid Input! Please enter an integer." << endl;  
    	return 1;
    }
    if (elements <1)
    {
	cout << "Game requires 2 or more players." << endl;
	return 1;
    }
    tree T1, T2;
    int x, y, z;
    bool negative;
    cout << "All input values must be 0 or greater." <<endl;
    for(int i = 0; i < elements; i++)
    {
	negative = true;
	// Take user input for data
	// If a number in one or more points is negative,
	// a note is given and the user must enter data again
	do{
	    cout << "Points for Element " << i+1 << ":" <<  endl;
	    cout << "Enter X val: ";
	    cin >> x;
	    cout << "Enter Y val: ";
	    cin >> y;
	    cout << "Enter Z val: ";
	    cin >> z;
	    // Negative check
       	    if(x >= 0 && y >= 0 && z >= 0)
            	negative = false;
	    else
		cout << "You didn't enter all positive integers!" << endl;
	} while (negative == true);
        T1.insertNode(x, y, z);
    }
    negative = true;
    node *holdT1Root = T1.getRoot(); 
    T1.printSymm(holdT1Root);
    T2.preTscribe(holdT1Root);
    T2.printPostorder(T2.getRoot());
    int probe;
    // Same as input for data except the input is only for the probe
    do{
        cout << "Enter the point you want to search for: ";
        cin >> probe;
	if(probe >= 0)
    	    negative = false;
	else
	    cout << "Please enter a positive integer for probe." <<endl;
    } while (negative == true);
    node *hold = NULL;
    T2.search(T2.getRoot(), hold, probe);
}

