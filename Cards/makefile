# CS315 Makefile for Program 1: Deck of Dequeues
# Feel free to modify as needed.
# Original author: Raphael Finkel 1/2020
CC = /usr/bin/g++
CPPFLAGS = -Wall -g

NUMPLAYERS = 4
NUMCARDS = 5
NUMTURNS = 1000

SEED = 43

# compile and run the student program, placing the result in tmpRun.out
run: cards randGen.pl
	./randGen.pl $(SEED) | ./cards $(NUMPLAYERS) $(NUMCARDS) $(NUMTURNS) > tmpRun.out
	less tmpRun.out

runAlt: cardsAlt randGen.pl
	./randGen.pl $(SEED) | ./cardsAlt $(NUMPLAYERS) $(NUMCARDS) $(NUMTURNS) > tmpAltrun.out
	less tmpAltrun.out

#List of sources
HEADER = *.h
EXEC = cards
EXEC2 = cardsAlt

$(EXEC): deck.o main.o
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(EXEC2): deck.o mainAlt.o
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

# compile and run a known working program, placing the result in tmpWorking.out
runWorking: workingCards randGen.pl
	./randGen.pl $(SEED) | ./workingCards $(NUMPLAYERS) $(NUMCARDS) $(NUMTURNS) > tmpWorking.out
	less tmpWorking.out
	
# get the randGen.pl program
randGen.pl:
	wget http://www.cs.uky.edu/~raphael/courses/CS315/prog1/randGen.pl
	chmod +x randGen.pl
	
# get the workingCards program
workingCards:
	wget http://www.cs.uky.edu/~raphael/courses/CS315/prog1/workingCards
	chmod +x workingCards
	
# Modify the following recipe to zip exactly what you want to include.
zipAll: clean
	zip toSubmit.zip *
										
.PHONY: clean
clean:
	rm *.o
	rm -f randGen.pl cards workingCards tmp* toSubmit.zipi
