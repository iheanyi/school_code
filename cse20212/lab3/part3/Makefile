all:	pmain

pmain: pmain.o Package.o TwoDayPackage.o OvernightPackage.o
	g++ pmain.o Package.o TwoDayPackage.o OvernightPackage.o -o pmain
Package.o:	Package.cpp
	g++ -c Package.cpp
TwoDayPackage.o:	TwoDayPackage.cpp
	g++ -c TwoDayPackage.cpp
OvernightPackage.o:	OvernightPackage.cpp
	g++ -c OvernightPackage.cpp
clean:
	rm -f *.o main
	rm -f *.o pmain