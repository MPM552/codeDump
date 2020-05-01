# CS315 Makefile for Program 4: Word Counter
# Feel free to modify as needed.
# Original author: Raphael Finkel 3/2020
CC = /usr/bin/g++  
CPPFLAGS = -Wall -g
GOAL = wordCount
GOAL2 = wordCountAlt
GOAL3 = wordCountTest
DATA = data.txt
TESTDATA = testdata.txt
HEADER = hash.h
WORKING = workingWordCount

# main compiler
$(GOAL): hash.o main.o
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

# altMain compiler
$(GOAL2): hash.o altMain.o
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

# compile and run the student program, placing the result in tmpRun.out
run: $(GOAL) $(DATA)
	./$(GOAL) < $(DATA) > tmpRun.out
	less tmpRun.out

runTest: $(GOAL) $(TESTDATA)
	./$(GOAL) < $(TESTDATA) > tmpTestRun.out
	less tmpTestRun.out


runAlt: $(GOAL2) $(DATA)
	./$(GOAL2) < $(DATA) > tmpRunAlt.out
	less tmpRunAlt.out

# run a known working program, placing the result in tmpWorking.out
runWorking: $(WORKING) $(DATA)
	./$(WORKING) < $(DATA) > tmpWorking.out
	less tmpWorking.out

# get the working program
$(WORKING):
	wget http://www.cs.uky.edu/~raphael/courses/CS315/prog4/$(WORKING)
	chmod +x $(WORKING)

# get the data
$(DATA):
	wget http://www.cs.uky.edu/~raphael/courses/CS315/prog4/$(DATA)

# Modify the following recipe to zip exactly what you want to include.
zipAll: 
	zip toSubmit.zip *.cpp  Makefile README.txt testdata.txt *.h *.out
	
.PHONY: clean
clean:
	rm -f $(GOAL) $(WORKING) $(DATA) tmp* toSubmit.zip
