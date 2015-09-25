# Authors: Raul Santelices, Brian DuSell
# Contact: cse30331fa12_tas@listserv.nd.edu
#
# You can add more files, but do not change existing file names
# 
# Course: CSE 30331

all: test_prog3

test_prog3: test_prog3.o train_sim.o
	g++ -Wall -o $@ $^ -g

train_sim.o: train_sim.cxx train_sim.h
	g++ -Wall -c $< -g 

test_prog3.o: test_prog3.cxx train_sim.h unit_test.h color.h
	g++ -Wall -c $< -g 

clean:
	rm -f test_prog3 *.exe *.o >& /dev/null
