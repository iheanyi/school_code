all: main

main:	main.o Puzzle.o
	g++ main.o Puzzle.o -o main -g

Puzzle.o: Puzzle.cpp
	g++ -c Puzzle.cpp -g

main.o:	main.cpp
	g++ -c main.cpp -g
clean:
	rm -f *.o main