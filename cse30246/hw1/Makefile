all: main

main: main.o parse.o
	g++ main.o parse.o -o main -g
parse.o:	parse.cpp
	  g++ -c parse.cpp -g
main.o:	main.cpp
	g++ -c main.cpp -g
clean:
	rm -f *.o main