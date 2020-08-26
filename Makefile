CXX = clang-7
CXXFLAGS = -w -pthread -lm

main: main.c ratio.c
	$(CXX) $(CXXFLAGS) -o main $^

all: clean main

run: clean main
	./main
	
clean:
	rm -f main
	rm -f ResistorValues
	rm -f ResistorCombinations
	