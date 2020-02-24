// deck.h: Contains the two classes, node and linkedlist. Node acting as the
// cards and linkedlist acting as the deck. Linkedlist is a friend class of 
// node so that it has access to the private data in node. Linkedlist contains
// the declarations of the functions used throughout main.

#include <iostream>
#include <sstream>

using namespace std;

// node class to make node objects with data, a next pointer,
// and a previous pointer
class node
{
    friend class linkedlist;
    public:
	node();
    private:
	int data;
	node *next;
	node *prev;
};

// linked list class to make deck objects with a head and tail
class linkedlist
{
    public:
	linkedlist();
	int deleteFront();
	int deleteBack();
	void insertFront(int newdata);
	bool emptyList();
	void printList();
	void arrayFill(int cards);
	int deckWeight();

    private:	
	node *head;
	node *tail;
};
