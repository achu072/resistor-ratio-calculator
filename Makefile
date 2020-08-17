CXX = gcc
CXXFLAGS = -Wall -g

main: main.cpp BookSeller.cpp BookSeller.h Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -o main $^

all: clean main

run: clean main
	./main
	
clean:
	rm -f main
	rm -f ResistorValues
	rm -f ResistorCombinations
	