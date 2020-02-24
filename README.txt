Name: Matthew Mitchell
Date: Created 1-21-20 Last Edit 1-29-20
Assignment: CS315 Programming Assignment: Deck of Dequeues
Purpose: Create a game with n players who are trying to be the first to
get rid of all their cards, c. Each game has a maximum of t turns. If a player
does not run out of cards before the last turn of the game, the player with 
the smallest pile wins. In the case of a tie, the lesser player number wins. 

Program Notes: The command line arguments for this program must be in the
order: players cards turns. To compile the program type "make" and click enter.
This will then run the program with n=4, c=5, and t=1000. You can the exit
by typing q. After you make, you can run the program by typing, with all 
variables being non-negative integers:
./randGen.pl seed | ./cards players cards turns

mainAlt: There is a different main file with alternate rules to the game. The
alternate program makes the two-sided die into a seven-sided die. If the die
rolls a seven the player who has advantage replaces their current deck with
the starting deck. If it rolls under 4, 0 to 3, the top gets moved and for 
else the bottom is moved, both as usual in the main program.
