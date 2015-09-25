all: main

main:	main.o CardDeck.o
	g++ main.o CardDeck.o -o main -g
main.o:	main.cpp
	g++ -c main.cpp -g

CardDeck.o:	CardDeck.cpp
	g++ -c CardDeck.cpp -g

clean:
	rm -f *.o main
