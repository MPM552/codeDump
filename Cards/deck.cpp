// deck.cpp: Contains definitions of the node and linkedlist constructors. Also 
// contains definitions of all functions in linkedlist. Each function has a 
// small description commented above describing what the function does. 

#include "deck.h"

using namespace std;

node::node(){
    data = 0;
    next = NULL;
    prev = NULL;
}

linkedlist::linkedlist(){
    head = NULL;
    tail = NULL;
}

// Delete first card in deck
// If only one card, deallocate head and next
int linkedlist::deleteFront()
{
    int frontData = head->data;
    node *remove = head;
    if (head->next == NULL)
    {
	delete remove;
	remove = NULL;
	head = NULL;
	tail = NULL;
	return(frontData);
    }
    else
    {
        head = head->next;
	head->prev = NULL;
	delete remove;
	remove = NULL;
	return(frontData);
    }
}

// Same as deleteFront except with the last card in deck
int linkedlist::deleteBack()
{
    int backData = tail->data;
    node *remove = tail;
    if (tail->prev == NULL)
    {
	delete remove;
	remove = NULL;
	head = NULL;
	tail = NULL;
	return(backData);
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
        delete remove;
        remove = NULL;
        return(backData);
    }
}

// Insert a new card on top of the deck
// If the deck is initially empty, the new card
// is the head and tail. Otherwise, pointers are
// changed accordingly
void linkedlist::insertFront(int newdata)
{
    node *newHead = new node;
    newHead->data = newdata;
    if(head == NULL)
    {
	head = newHead;
	tail = newHead;
    }
    else
    {
    	head->prev = newHead;
	newHead->next = head;
	head = newHead;
    }
}

// Checks if a deck is empty
bool linkedlist::emptyList()
{
    if (head == NULL)
	return true;
    else
	return false;
}	

// Print each card of a deck
void linkedlist::printList()
{
    if (head == NULL)
	cout << endl;
    else
    {
    	cout << head->data << " ";
    	node *current = head->next;
    	while (current != NULL){
	    cout << current->data << " ";
	    current = current->next;
    	}
   	 cout << endl;
    }
} 

// Creates a deck of cards with the deck being
// "cards" length and each card being equal to
// its depth
void linkedlist::arrayFill(int cards)
{
	for(int i = cards; i > 0; i--)
	    insertFront(i);
}

// Gives the weight of a deck. Calculated
// by multiplying the data of a card by
// its depth in the deck, weight.
int linkedlist::deckWeight()
{
    int deckWeight = 0;
    if (head == NULL)
	return deckWeight;
    else
    {
	int weight = 1;
   	deckWeight = head->data;
    	node *current = head->next;
    	while (current != NULL){
	    weight = weight + 1;
	    deckWeight = deckWeight + (current->data * weight);
	    current = current->next;
    	}
   	return deckWeight;
    }
}

