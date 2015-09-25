all:	main mainr
 
main: main.o C4Col.o C4Board.o
	g++ main.o C4Col.o C4Board.o -o main -g
main.o:	main.cpp
	g++ -c main.cpp -g
C4Col.o: C4Col.cpp
	g++ -c C4Col.cpp -g
C4Board.o:	C4Board.cpp
	g++ -c C4Board.cpp -g

mainr:	mainr.o Rational.o
	g++ mainr.o Rational.o -o mainr -g
mainr.o: mainr.cpp
	g++ -c mainr.cpp -g
Rational.o: Rational.cpp
	g++ -c Rational.cpp -g

clean:
	rm -f *.o main
	rm -f *.o mainr
  