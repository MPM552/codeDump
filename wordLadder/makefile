# build Project3
CC = /usr/bin/g++
EXEC = CS216PA3
HEADERS = WordLadder.h Graph.h
$(EXEC): WordLadder.o Graph.o main.o
	$(CC) $^ -o $@
%.o: %.cpp $(HEADERS)
	$(CC) -c $< -o $@
clean:
	rm -i *.o
	rm -i `find ./ -type f -executable`

