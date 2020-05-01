#include "hash.h"

using namespace std;
// Constructs internal node without string
extNode::extNode(){
    key = -1;
    count = 0;
    next = NULL;
    word = "";
}//extNode()
// Constructs internal node given a string. Determines key from 
// string and checks that key is within bounds.
extNode::extNode(string input){
    int keycount = 0;  
    word = input;
    for(unsigned int i = 0; i < input.length(); i++)
        keycount = keycount + input.at(i);
    if (keycount >= LENGTH)
	keycount = keycount % LENGTH;
    key = keycount;
    count = 1;
    next = NULL;

}// extNode()
// Internal nodes act as a check to see if a position in the table 
// contains data or not. If it doesn't, the print function continues
// to the next position. Points to the first data node, firstExt, if it
// is present.
intNode::intNode(){
    empty = true;
    firstExt = NULL;
}// intNode()

hashTable::hashTable(){}// hashTable()
// Set up internal nodes in hashTable
void hashTable::SetUp(){
    for(int i = 0; i < LENGTH; i++){
        intNode *checkNode = new intNode;
	nodeList[i] = *checkNode;
    }  
}//SetUp()
// Insert a new node into hash table
void hashTable::insertNode(extNode *addMe){
    // Check if spot in table is empty if so make it the first element
    if (nodeList[addMe->key].empty == true){
        nodeList[addMe->key].firstExt = addMe;
	nodeList[addMe->key].empty = false;
    }
    // Otherwise, dive down the list until the last element is reached
    // then place it after.
    else{
	extNode *checkWord = nodeList[addMe->key].firstExt;
	extNode *addAfter = NULL;
        while(checkWord != NULL){
	    // Check if the word is already present
	    if(checkWord->word == addMe->word){
		checkWord->count = checkWord->count + 1;
		return;
	    }
	    addAfter = checkWord;
	    checkWord = checkWord->next;
	}
	addAfter->next = addMe;
    } 
  
}//insertNode()
// printPositions is a test function for checking that all words get 
// into the hash table. Not used in actual main.cpp
void hashTable::printPositions(){
    for(int i = 0; i < LENGTH; i++){
	cout << i << ": ";
	if(nodeList[i].empty == false){
	    int counter = 0;
	    extNode *dive = nodeList[i].firstExt;
	    while(dive != NULL){
                counter = counter + 1;
	        dive = dive->next;
	    }
	    cout << counter << " nodes long.";
	}
	else
	    cout << "0 nodes long.";
	cout << endl;
    }
    cout << endl;
    
}// printPositions

// Partition from geeksforgeeks, compares points and swaps as necessary
// Used as partition for print sorted by word count then alphabetically
int extNode::partitionCount(extNode array[], int lowI, int highI){
    int pivotCount = array[highI].count; // pivotcount
    string pivotWord = array[highI].word; // pivotword
    int i = lowI - 1; // i of smaller element
    // Testing here until for loop
    for (int j = lowI; j <= highI - 1; j++){
        if (array[j].count > pivotCount) // MAKE THIS COMPARISON OF INTS
	{
	    i++;
	    extNode hold1 = array[i];
	    array[i] = array[j];
	    array[j] = hold1;
	}
	else if (array[j].count == pivotCount){
	    if (array[j].word < pivotWord){
	        i++;
	        extNode hold1 = array[i];
	        array[i] = array[j];
	        array[j] = hold1;
	    }
	}
    }
    extNode hold2 = array[i+1];
    array[i+1] = array[highI];
    array[highI] = hold2;
    return(i+1);
}// partition(extNode array[], int lowI, int highI)
// Same partition algorithm for sorting alphabetically
int extNode::partitionWord(extNode array[], int lowI, int highI){
    string pivot = array[highI].word; // pivot
    int i = lowI - 1; // i of smaller element
    for (int j = lowI; j <= highI - 1; j++){
        if (array[j].word < pivot) // MAKE THIS COMPARISON OF STRINGS
	{
	    i++;
	    extNode hold1 = array[i];
	    array[i] = array[j];
	    array[j] = hold1;
	}
    }
    extNode hold2 = array[i+1];
    array[i+1] = array[highI];
    array[highI] = hold2;
    return(i+1);
}// partition(extNode array[], int lowI, int highI)


// Quicksort algorithm from geeksforgeeks used for alphabetical sort
void extNode::quickSortWord(extNode array[], int lowI, int highI){
    if (lowI < highI){
	int partI = partitionWord(array, lowI, highI);
	quickSortWord(array, lowI, partI-1);
	quickSortWord(array, partI + 1, highI);
    }
} // quickSort(extNode array[], int lowI, int highI)

// Quicksort algorithm from geeksforgeeks used for integer sort
void extNode::quickSortCount(extNode array[], int lowI, int highI){
    if (lowI < highI){
	int partI = partitionCount(array, lowI, highI);
	quickSortCount(array, lowI, partI-1);
	quickSortCount(array, partI + 1, highI);
    }
} // quickSort(extNode array[], int lowI, int highI)


// printAlpha: print words with counts in alphabetical order
void hashTable::printAlpha(int wordCount){
    extNode *sortMe = new extNode[wordCount];
    int j = 0;
    // Look through each chain containing data
    for(int i = 0; i != LENGTH; i++)
    {
        if(nodeList[i].empty == false){
	    extNode *dive = nodeList[i].firstExt;
	    // Add data to array
	    while(dive != NULL){
                sortMe[j] = *dive;
	        j = j + 1;
	        dive = dive->next;
	    }
	}
    }
    int count = 0;      
    // Sort the array
    sortMe->quickSortWord(sortMe, 0, j-1);
    // Print the array
    for(int i = 0; i < j; i++){
        cout << sortMe[i].word << " " << sortMe[i].count << endl;
	count = count + sortMe[i].count;
    }
    cout << endl;
}// printAlpha()

// Print elements numerically. If there is a tie, print 
// alphabetically. Works essentially the same as printAlpha().
void hashTable::printNumerical(int wordCount){
    extNode *sortMe2 = new extNode[wordCount];
    int j = 0;
    for(int i = 0; i != LENGTH; i++)
    {
        if(nodeList[i].empty == false){
	    extNode *dive = nodeList[i].firstExt;
	    while(dive != NULL){
                sortMe2[j] = *dive;
	        j = j + 1;
	        dive = dive->next;
	    }
	}
    }
    int count = 0;      
    sortMe2->quickSortCount(sortMe2, 0, j-1);
    for(int i = 0; i < j; i++){
        cout << sortMe2[i].word << " " << sortMe2[i].count << endl;
	count = count + sortMe2[i].count;
    }
} // printNumerical()

// altMain Functions
// All of these functions are the same as the ones above. They include 
// extra lines for counting comparisons.

int extNode::partitionCountStat(extNode array[], int lowI, int highI, 
int &comparisons){
    int pivotCount = array[highI].count; // pivotcount
    string pivotWord = array[highI].word; // pivotword
    int i = lowI - 1; // i of smaller element
    for (int j = lowI; j <= highI - 1; j++){
	comparisons = comparisons + 1; // if statement
        if (array[j].count > pivotCount) // MAKE THIS COMPARISON OF INTS
	{
            i++;
	    extNode hold1 = array[i];
	    array[i] = array[j];
	    array[j] = hold1;
	}
	else if (array[j].count == pivotCount){
	    comparisons = comparisons + 1; // else if statement
	    comparisons = comparisons + 1; // if statement
	    if (array[j].word < pivotWord){
		i++;
	        extNode hold1 = array[i];
	        array[i] = array[j];
	        array[j] = hold1;
	    }
	}
    }
    extNode hold2 = array[i+1];
    array[i+1] = array[highI];
    array[highI] = hold2;
    return(i+1);
}// partition(extNode array[], int lowI, int highI)

int extNode::partitionWordStat(extNode array[], int lowI, int highI, 
int &comparisons){
    string pivot = array[highI].word; // pivot
    int i = lowI - 1; // i of smaller element
    for (int j = lowI; j <= highI - 1; j++){
	comparisons = comparisons + 1; // if statement
        if (array[j].word < pivot) // MAKE THIS COMPARISON OF STRINGS
	{
	    i++;
	    extNode hold1 = array[i];
	    array[i] = array[j];
	    array[j] = hold1;
	}
    }
    extNode hold2 = array[i+1];
    array[i+1] = array[highI];
    array[highI] = hold2;
    return(i+1);
}// partition(extNode array[], int lowI, int highI)

// quickSort algorithm from geeksforgeeks used for alphabetical sort
void extNode::quickSortWordStat(extNode array[], int lowI, int highI, 
int &comparisons){
    comparisons += 1; // if statement
    if (lowI < highI){
	int partI = partitionWordStat(array, lowI, highI, comparisons);
	quickSortWordStat(array, lowI, partI-1, comparisons);
	quickSortWordStat(array, partI + 1, highI, comparisons);
    }
} // quickSort(extNode array[], int lowI, int highI)

// quickSort algorithm from geeksforgeeks used for alphabetical sort
void extNode::quickSortCountStat(extNode array[], int lowI, int highI, 
int &comparisons){
    comparisons += 1; // if statement
    if (lowI < highI){
	int partI = partitionCountStat(array, lowI, highI, comparisons);
	quickSortCountStat(array, lowI, partI-1, comparisons);
	quickSortCountStat(array, partI + 1, highI, comparisons);
    }
} // quickSort(extNode array[], int lowI, int highI)

// printAlpha: print words with counts in alphabetical order
void hashTable::printAlphaStat(int wordCount, int &comparisons){
    extNode *sortMe = new extNode[wordCount];
    int j = 0;
    // Look through each chain containing data
    for(int i = 0; i != LENGTH; i++)
    {
        if(nodeList[i].empty == false){
	    extNode *dive = nodeList[i].firstExt;
	    // Add data to array
	    while(dive != NULL){
                sortMe[j] = *dive;
	        j = j + 1;
	        dive = dive->next;
	    }
	}
    }
    int count = 0;      
    // Sort the array
    sortMe->quickSortWordStat(sortMe, 0, j-1, comparisons);
    // print the array
    for(int i = 0; i < j; i++){
        cout << sortMe[i].word << " " << sortMe[i].count << endl;
	count = count + sortMe[i].count;
    }
    cout << endl;
}// printAlpha()

// Print elements numerically. If there is a tie, print 
// alphabetically. Works essentially the same as printAlpha().
void hashTable::printNumericalStat(int wordCount, int &comparisons){
    extNode *sortMe2 = new extNode[wordCount];
    int j = 0;
    for(int i = 0; i != LENGTH; i++)
    {
        if(nodeList[i].empty == false){
	    extNode *dive = nodeList[i].firstExt;
	    while(dive != NULL){
                sortMe2[j] = *dive;
	        j = j + 1;
	        dive = dive->next;
	    }
	}
    }
    int count = 0;      
    sortMe2->quickSortCountStat(sortMe2, 0, j-1, comparisons);
    for(int i = 0; i < j; i++){
        cout << sortMe2[i].word << " " << sortMe2[i].count << endl;
	count = count + sortMe2[i].count;
    }
} // printNumerical()

// Insert a new node into hash table
void hashTable::insertNode(extNode *addMe, int &searches){
    // Adds one for empty comparison
    searches += 1; // is statement
    // Check if spot in table is empty if so make it the first element
    if (nodeList[addMe->key].empty == true){
        nodeList[addMe->key].firstExt = addMe;
	nodeList[addMe->key].empty = false;
    }
    // Otherwise, dive down the list until the last element is reached
    // then place it after.
    else{
	extNode *checkWord = nodeList[addMe->key].firstExt;
	extNode *addAfter = NULL;
	// Adds one for NULL check
        while(checkWord != NULL){
	    searches += 1; // while comparison
	    // Check if the word is already present
	    if(checkWord->word == addMe->word){
		// Adds one for word check
		searches += 1; // if statement
		checkWord->count = checkWord->count + 1;
		return;
	    }
	    addAfter = checkWord;
	    checkWord = checkWord->next;
	}
	addAfter->next = addMe;
    } 
  
}//insertNode()

