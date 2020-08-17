CXX = gcc
CXXFLAGS = -Wall -g

main: main.c
	$(CXX) $(CXXFLAGS) -o main $^

all: clean main

run: clean main
	./main
	
clean:
	rm -f main
	rm -f ResistorValues
	rm -f ResistorCombinations
	