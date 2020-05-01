#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Size of hash table
const int LENGTH = 127;

// extNode class: Holds useful data that is stored in hash table.
class extNode{
    friend class hashTable;
    public:
        extNode();
	// main
        extNode(string input);
	int partitionWord(extNode array[], int lowI, int highI);	
	void quickSortWord(extNode array[], int lowI, int highI);
	int partitionCount(extNode array[], int lowI, int highI);	
	void quickSortCount(extNode array[], int lowI, int highI);
	// altMain	
	void quickSortWordStat(extNode array[], int lowI, int highI, 
	int &comparisons);
	void quickSortCountStat(extNode array[], int lowI, int highI, 
	int &comparisons);
	int partitionWordStat(extNode array[], int lowI, int highI, 
	int &comparisons);
	int partitionCountStat(extNode array[], int lowI, int highI, 
	int &comparisons);


    private:
        string word;
        int key;
	int count;
	extNode *next;
};
// intNode class: Handles inserting new data and tells sorting if 
// there is data at a table position of not.
class intNode{
    friend class hashTable;
    public:
	intNode();
    private:
	bool empty;
	extNode *firstExt;
};

// hashTable class: Handles all methods for hashing and sorting
class hashTable{
    friend class extNode;
    friend class intNode;
    public:
        hashTable();
	// main
	void SetUp();
        void insertNode(extNode *addMe);
	void swap(int *a, int *b);
	void printAlpha(int wordCount);
	void printNumerical(int wordCount);		
	// altMain functions
	void insertNode(extNode *addMe, int &searches);	
	void printPositions();
	void printAlphaStat(int wordCount, int &comparisons);
        void printNumericalStat(int wordCount, int &comparisons);
	
    private:
	intNode nodeList[LENGTH];

};

