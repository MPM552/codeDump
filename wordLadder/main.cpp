 /*
 * File: main.cpp
 * Course: CS216-002
 * Project: PA3
 * Purpose: Create a word ladder between any two words in the input file of the same
 * length. Gives each word in the word ladder from word1 to word2 and tells the user 
 * how many total words are in the ladder, including word1 and word2.
 */

#include "WordLadder.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	// Check whether the number of command line arguments is exactly one 
	if (argc != 2)
	{
		cout << "Warning: need exactly one command line argument." << endl;
		cout << "Usage: " << argv[0] << " inputfile_name" << endl;
        	return 1;
    	}

    	ifstream in_file;
    	in_file.open(argv[1]);

    	// Check whether the input file can be open successfully or not
    	if (!in_file.good())
    	{
        	cout << "Warning: cannot open file named " << argv[1] << "!" << endl;
        	return 2;
    	}

	vector<string> wordList; 

	// Put words from input file into vector
	while (!in_file.eof()){
		string word;
		in_file >> word;
		wordList.push_back(word);
	}

	string word1, word2;
	WordLadder wordStruct(wordList);
	
	while (true){

        	cout << endl << endl;
        	cout << "Welcome to CS216 Word Ladder!" << endl;
        	cout << "Please give me two English words, and I will convert the first into the second by modifying one letter at a time." << endl;
        	cout << "Please type the FIRST word (or type Enter to quit): " << endl;
		getline(cin, word1);
        
        	if (word1 == "")
            		break;
        
        	cout << "Please type the SECOND word (or type Enter to quit): " << endl;
	    	getline(cin, word2);
        
        	if (word2 == "")
            		break;
        	// convert both word1 and word2 to all lower-case letters
        	transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
        	transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
	
		if (word1.length() != word2.length())
		{
			cout << "The two words must be the same length!" << endl;
			cout << "There is no ladder from [" << word1 << "] to [" << word2 << "]" << endl;
			continue;
		}

		if (word1 == word2)
		{
			cout << "The two words must be different!" << endl;
			continue;
		}
		// transfer word ladder to vector	
		vector<string> wordPath = wordStruct.getLadder(word1, word2);
		if (wordPath.size() == 0)
		{
			cout << "There is no ladder from " << "[" << word1 << "] to [" << word2 << "]" << endl;
			continue;
		}
		cout << "The ladder for " << word1 << " to " << word2 << " is " << wordPath.size() << " word(s) long." << endl;
		cout << "A ladder from [" << word1 << "] to [" << word2 << "]:" << endl;
		// create vector to hold the ladder
		for (int i = 0; i < wordPath.size()-1; i++)
			cout << wordPath[i] << " ---> ";
		cout << word2;
	}

	cout << "Have a beautiful day. See you next time..." << endl;

}


