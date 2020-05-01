#include "hash.h"

using namespace std; 

int main(){
    string word; 
    int wordCount = 0;
    hashTable H1;
    // Set up hash table with internal nodes
    H1.SetUp();
    // Cin words from text document
    while((cin >> word)){
        wordCount = wordCount + 1;
        extNode *newExt = new extNode(word);
	
	// Insert node into hash table
        H1.insertNode(newExt);
    }
    // Print sorted data from hash table
    H1.printAlpha(wordCount);
    H1.printNumerical(wordCount);
    return 0;
}
