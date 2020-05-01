# CS315 Makefile for Program 2: Trees
# Feel free to modify as needed.
# Original author: Raphael Finkel 1/2020

CPPFLAGS = -Wall -g
GOAL = kd
HEADER = *.h
CC = /usr/bin/g++ 
NUMPOINTS = 10
SEED = 43
MODULUS = 1000
NUMPROBES = 2

$(GOAL): trees.o main.o
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

# compile and run the student program, placing the result in tmpRun.out
run: $(GOAL) randGen.pl
	./randGen.pl $(SEED) $(MODULUS) | \
		./$(GOAL) $(NUMPOINTS) $(NUMPROBES) > tmpRun.out
	less tmpRun.out

# compile and run a known working program, placing the result in tmpWorking.out
runWorking: workingKD randGen.pl
	./randGen.pl $(SEED) $(MODULUS) | \
		./workingKD $(NUMPOINTS) $(NUMPROBES) > tmpWorking.out
	less tmpWorking.out

# get the randGen.pl program
randGen.pl:
	wget http://www.cs.uky.edu/~raphael/courses/CS315/prog1/randGen.pl
	chmod +x randGen.pl

# get the workingTrees program
workingKD:
	wget http://www.cs.uky.edu/~raphael/courses/CS315/prog3/workingKD
	chmod +x workingKD

# Modify the following recipe to zip exactly what you want to include.
zipAll: 
	zip toSubmit.zip trees.*  main.cpp Makefile README.txt tmpRun.out
	
.PHONY: clean
clean:
	rm -f randGen.pl $(GOAL) workingTrees tmp* toSubmit.zip
