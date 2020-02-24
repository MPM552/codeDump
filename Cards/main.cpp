// Main: Uses the node and linkedlist classes to play the game cards.
// Contains a couple parts: taking command line args, declaring important
// structures/variables, going through turns, and end game check if all turns
// are used. 

#include "deck.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc !=4)
    {
	cout << "Warning: need exactly three command line arguments." << endl;
	cout << "Usage: " << argv[0] << " players cards turns" << endl;
	return 1;
    }
    // Assign iss variables to each command line argument
    istringstream iss( argv[1] );
    int players;
    istringstream iss2( argv[2] );
    int cards;
    istringstream iss3( argv[3] );
    int turns;
    
    // Check for valid input
    if (iss >> players)
	cout << "Players : " << players << endl;
    else 
    {
	cout << "Invalid Input! Please enter an integer." << endl;  
    	return 1;
    }
    if (players < 2)
    {
	cout << "Game requires 2 or more players." << endl;
	return 1;
    }
    if (iss2 >> cards)
    {
	cout << "Cards: " << cards << endl;
    }
    else 
    {
	cout << "Invalid Input! Please enter an integer." << endl;  
    	return 1;
    }
    if (cards < 1)
    {
	cout << "Game requires 1 or more cards." << endl;
	return 1;
    }
    if (iss3 >> turns)
    {
	cout << "Turns: " << turns << endl;
    }
    else 
    {
	cout << "Invalid Input! Please enter an integer." << endl;  
	return 1;
    }
    if (turns < 1)
    {
	cout << "Game requires 1 or more turns to play." << endl;
	return 1;
    }
    // Declare variables used throughout turns
    int winner, deckScore, rand, firstPlayer, receiver = 0;
    // Make an array that holds each player's deck
    linkedlist *deckArray = new linkedlist[players];
    for (int i = 0; i < players; i++)
    {
    	deckArray[i].arrayFill(cards);
	cout << "Player " << i+1 << ": ";
	deckArray[i].printList();
    }	
    // Declare and initialize arrays with turns and receives taken per player
    cout << endl;
    int turnTake[turns];
    int cardsTake[turns];
    for (int i; i < players; i++)
    {
	cardsTake[i] = 0;
	turnTake[i] = 0;
    }
    // The process for each turn
    for (int i = 0; i < turns; i++)
    {
	// Pick a player to give and a player to receive
	// Make note of these in turnTake and cardsTake
	cout << "Turn " << i+1 << ": ";	    
	cin >> rand;
     	firstPlayer = (rand % players);	
	turnTake[firstPlayer] = turnTake[firstPlayer] + 1;
	int frontData, backData;	
    	cout << "Player " << firstPlayer+1 << " sends their ";
	cin >> rand;
	int twoside = rand % 2;
	cin >> rand;
	receiver = (rand % players);
	cardsTake[receiver] = cardsTake[receiver] + 1;
	// Remove cards from chosen player's deck, top or bottom, 
	// and send the card to the receiver. 
	if (twoside == 0)
	{
	    cout << "top ";
	    frontData = deckArray[firstPlayer].deleteFront();
	    deckArray[receiver].insertFront(frontData);
	}
    	else  
	{
	    cout << "bottom ";
	    backData = deckArray[firstPlayer].deleteBack();
	    deckArray[receiver].insertFront(backData);
	}
	cout << "to player " << receiver+1 << "." << endl;
	bool checkwin = false;
	bool exit = false;
	// For each player, print deck and deck weight 
	for (int i = 0; i < players; i++)
	{
	    cout << "Player " << i+1 << ": ";
	    deckArray[i].printList();
	    deckScore = deckArray[i].deckWeight();
	    cout << "Deck Score: " << deckScore << endl;
	    checkwin = deckArray[i].emptyList();
	    // Check for a winner with an empty deck
	    if (checkwin)
	    {
		winner = i+1;
		exit = true;
	    }
	}
	cout << endl;
	// If a player has won the game will begin its end phase
	if (exit)
	{
	    cout << "Game has ended!" << endl;
	    cout << "Results: " << endl;
	    for (int i = 0; i < players; i++)
    	    {
		deckScore = deckArray[i].deckWeight();
		cout << "Player " << i+1 << " score: " << deckScore << endl;
	    }
	    cout << "Player " << winner << " wins!" << endl;
	    cout << "Stats: " << endl;
	    for(int j = 0; j < players; j++)
	    {
		cout << "Player " << j+1 << " went " << turnTake[j]; 
		cout << " times ";
		cout << "and received " << cardsTake[j] << " cards." << endl;
	    }
	    return 0;
	}	
    }
    int winScore = ((cards)*(cards+1)*(2*cards+1))/6;
    cout << "Game has ended!" << endl;
    cout << "Results: " << endl;
    // Once the turns have been exhausted, the winner must be calculated
    // from the weight of each deck
    for (int i = 0; i < players; i++)
    {
    	deckScore = deckArray[i].deckWeight();
	cout << "Player " << i+1 << " score: " << deckScore << endl;
	if (deckScore < winScore)
	{
	    winner = i+1;
	    winScore = deckScore;
	}
	else if (deckScore == winScore)
	{
	    if (winner > i+1)
		winner = i+1;
	}
    } 
    // The player with the least weight wins
    cout << "Player " << winner << " wins!" << endl;
    cout << "Stats: " << endl;
    for(int i = 0; i < players; i++)
    {
	cout << "Player " << i+1 << " went " << turnTake[i] << " times ";
	cout << "and received " << cardsTake[i] << " cards." << endl;
    }
}
