CXX = clang-7
CXXFLAGS = -pthread -lm

main: main.cpp
	$(CXX) $(CXXFLAGS) -o main $^

all: clean main

run: clean main
	./main
	
clean:
	rm -f main
	rm -f ResistorValues
	rm -f ResistorCombinations
	