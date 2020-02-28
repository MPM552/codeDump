# CS315 Makefile for Program 2: Trees
# Feel free to modify as needed.
# Original author: Raphael Finkel 1/2020

CPPFLAGS = -Wall -g
GOAL = trees
GOAL2 = treesAlt
CC = /usr/bin/g++ 
HEADER = *.h
NUMPOINTS = 10
ALTPOINTS = 4
SEED = 43

# compile and run the student program, placing the result in tmpRun.out
run: trees randGen.pl
	./randGen.pl $(SEED) | ./$(GOAL) $(NUMPOINTS) > tmpRun.out
	less tmpRun.out

# compile and run alternate program
# no randGen.pl bc the program is all user input
# no tmpRun.out for same reason
runAlt: $(GOAL2) randGen.pl
	./$(GOAL2) $(ALTPOINTS)
	

# make and compile files needed to run main program
$(GOAL): trees.o main.o
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

# make and compile files needed to run altMain program
$(GOAL2): trees.o mainAlt.o
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@


# compile and run a known working program, placing the result in tmpWorking.out
runWorking: workingTrees randGen.pl
	./randGen.pl $(SEED) | ./workingTrees $(NUMPOINTS) > tmpWorking.out
	less tmpWorking.out
	
# get the randGen.pl program
randGen.pl:
	wget http://www.cs.uky.edu/~raphael/courses/CS315/prog1/randGen.pl
	chmod +x randGen.pl

# get the workingTrees program
workingTrees:
	wget http://www.cs.uky.edu/~raphael/courses/CS315/prog2/workingTrees
	chmod +x workingTrees

# Modify the following recipe to zip exactly what you want to include.
zipAll: 
	zip toSubmit.zip trees.cpp trees.h  main.cpp mainAlt.cpp makefile README.txt tmpRun.out
	
.PHONY: clean
clean:
	rm -f randGen.pl $(GOAL) $(GOAL2) workingTrees tmp* toSubmit.zip
