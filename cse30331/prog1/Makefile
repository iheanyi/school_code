all: test_prog2

test_prog2: test_prog2.o
	g++ -o test_prog2 test_prog2.o -g

test_prog2.o: test_prog2.cxx simple_string.h
	g++ -c test_prog2.cxx -g

#driver:	driver.o
#	g++ -Wall -o driver driver.o -g 

#driver.o: driver.cxx simple_string.h
#	g++ -c driver.cxx -Wall -g


#clean:
#	rm -f *.o test_prog1

clean:
	rm -f test_prog2 *.exe *.o 2>/dev/null
#	rm -f *.o
