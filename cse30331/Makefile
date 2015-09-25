# Authors: Brian DuSell
#          Raul Santelices
# Contact: cse30331fa12_tas@listserv.nd.edu
#
# Do not modify this file.
# 
# Course: CSE 30331

all: test_prog2

test_prog2: test_prog2.o pqueue.o
	g++ -Wall -o $@ $^

pqueue.o: pqueue.cxx pqueue.h
	g++ -Wall -c $<

test_prog2.o: test_prog2.cxx pqueue.h unit_test.h color.h
	g++ -Wall -c $<

clean:
	rm -f test_prog2 *.exe *.o >& /dev/null
