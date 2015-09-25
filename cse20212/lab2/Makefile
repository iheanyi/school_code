all:	main mainr
 
main: main.o C4Col.o C4Board.o
	g++ main.o C4Col.o C4Board.o -o main
main.o:	main.cpp
	g++ -c main.cpp
C4Col.o: C4Col.cpp
	g++ -c C4Col.cpp
C4Board.o:	C4Board.cpp
	g++ -c C4Board.cpp

mainr:	mainr.o Rational.o
	g++ mainr.o Rational.o -o mainr
mainr.o: mainr.cpp
	g++ -c mainr.cpp
Rational.o: Rational.cpp
	g++ -c Rational.cpp

clean:
	rm -f *.o main
	rm -f *.o mainr
  