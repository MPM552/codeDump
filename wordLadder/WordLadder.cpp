 /*
 * File: WordLadder.cpp
 * Course: CS216-002
 * Project: PA3
 * Purpose: Implementation of WordLadder class 
 *
 */

#include "WordLadder.h"


using namespace std;

// default constructor
WordLadder::WordLadder(){
}
//alternate constructor
WordLadder::WordLadder(const vector<string>& words){
	for (auto i = words.begin(); i != words.end(); i++)
		insertWord(*i);
}

// First access the map of all words 
// The key is length, the value is the vector of words
// with the length given in the key
void WordLadder::insertWord(string newword){
	wordsByLength[newword.length()].push_back(newword);	
}
	   
// return a graph from the group of words with the same lengths = length
// there is an edge between two words
// if two words are only different in a single letter
Graph<string> WordLadder::WordsGraph(int length) const{
	vector<string> wordlist =  wordsByLength.find(length)->second;
	map<string, vector<string> > wordBuckets;
	// Create "buckets" of words that have the same structure
	// when a single letter is replaced by '?'
	for (auto i = wordlist.begin(); i != wordlist.end(); i++)
	{
		for (int j = 0; j < length; j++)
		{
			string temp = *i;
			temp[j] = '?';
			wordBuckets[temp].push_back(*i);
		}
		
	}
	// Create a graph of asscoiated words. This graph has an
	// edge between each word with a one letter difference. 
	Graph<string> AsWords;
	for (auto i = wordBuckets.begin(); i != wordBuckets.end(); i++)
	{
		vector<string> tempword = i->second;
		for (int j = 0; j < tempword.size(); j++)
		{
			for (int k = j + 1; k < tempword.size(); k++)
			{
				AsWords.addEdge(tempword[j], tempword[k]);	
			}
			
		}
	}
	return AsWords;

}
// return a vector of words
// which represents a word ladder from word1 to word2
// any two adjacent words along the ladder differ in only one character
vector<string> WordLadder::getLadder(string word1, string word2) const{
	// declare new data structures
	vector<string> words;
	map<string,int> distance;
	map<string, string> go_through;
	Graph<string> WGraph = WordsGraph(word1.length());
	map <string, string> corrected;
	int dist = WGraph.BFS(word1, word2, distance, go_through);
	string NextV = word2;
	if (dist == INVALID_VERTEX || dist == NOPATH)
		return words;
	// make map "corrected" that is reversal of "go_through"
	while (go_through[NextV] != word1){
		corrected[go_through[NextV]] = NextV;	
		NextV = go_through[NextV]; 
	}
	corrected[word1] = NextV;
	NextV = word1;
	while (NextV != word2){
		words.push_back(NextV);	
		NextV = corrected[NextV];
	}
	words.push_back(word2);
	// use bfs to search through graph for shortest path between words
	// Find a way to add each word in the path to the vector
	
}


