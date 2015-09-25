// test_prog3.cxx
//
// Authors: Raul Santelices, Brian DuSell
// Contact: cse30331fa12_tas@listserv.nd.edu
//
// Do not modify this file.
//
// Course: CSE 30331, Fall 2012

// Description:
//	The test program which will be used for grading P.A. #3

#include <iostream>
#include "unit_test.h"
#include "train_sim.h"

using namespace std;

typedef unsigned int uint;

// Some data for the tests
const char* stations[] = { "South Bend", "Detroit", "Toronto", "Buffalo", "Cleveland", "Chicago", "Louisville", "Atlanta" };
const uint NUM_STAT = sizeof(stations) / sizeof(char*);
struct CONN {
	const char* from;
	const char* to;
	uint dist;
} connections[] = { {"Chicago", "South Bend", 1u}, {"South Bend", "Detroit", 5u}, {"South Bend", "Cleveland", 6u}, {"Detroit", "Cleveland", 2u}, {"Detroit", "Toronto", 8u}, {"Toronto", "Buffalo", 7u}, {"Buffalo", "Cleveland", 6u},
					{"Cleveland", "South Bend", 5u}, {"Cleveland", "Atlanta", 10u}, {"Cleveland", "Louisville", 6u}, {"Louisville", "Atlanta", 5u}, {"Louisville", "Chicago", 9u}, {"Atlanta", "South Bend", 12u}, {"Atlanta", "Buffalo", 11u} };
const uint NUM_CONN = sizeof(connections) / sizeof(CONN);

struct TRAIN {
	const char* name;
	uint wagons;
	const char* station;
} trains[] = { {"Choo Choo", 5u, "Chicago"}, {"Jimmy", 3u, "Chicago"}, {"Jackie", 1u, "Atlanta"}, {"Maureen", 2u, "Louisville"}, {"Johnny", 58u, "Cleveland"}, {"Alex", 6u, "Cleveland"}, {"Connie", 4u, "Cleveland"},
			   {"Tara", 7u, "Cleveland"}, {"Andy", 2u, "Toronto"}, {"Charlie", 6u, "Buffalo"}, {"Lukas", 2u, "Atlanta"}, {"Derrick", 10u, "Louisville"}, {"Rachael", 4u, "Detroit"}, {"Harry", 5u, "Detroit"} };
const uint NUM_TRAINS = sizeof(trains) / sizeof(TRAIN);

// Tester class for TrainSimulator
class TrainSimTester : public unit_test {
protected:
	virtual void run_impl() {
		// Part 1: tests for stations only
		run_part1();
		// Part 2: tests for trains only
		run_part2();
		// Part 3: combined tests for running simulation
		run_part3();
	}

	// Part 1: tests for stations only
	void run_part1() {
		TrainSimulator sim;
		sim.addStation("Atlanta");
		sim.addStation("South Bend");
		sim.connectStations("Atlanta", "South Bend", 7);

		sim.print();
		cout << endl;

		// tests #1 - #5
		UNIT_TEST_TRUE(sim.stationExists("Atlanta"), "Atlanta station exists");
		UNIT_TEST_TRUE(sim.stationExists("South Bend"), "South Bend station exists");
		UNIT_TEST_TRUE(sim.stationsConnected("Atlanta", "South Bend"), "ATL->SB are connected");
		UNIT_TEST_TRUE(!sim.stationsConnected("South Bend", "Atlanta"), "Stations are not connected in the other direction");
		UNIT_TEST_EQUAL(sim.connectionLength("Atlanta", "South Bend"), 7u, "Connection length SB->ATL is correct");

		sim.removeStation("Atlanta");

		sim.print();
		cout << endl;

		// tests #6 - #7
		UNIT_TEST_TRUE(!sim.stationExists("Atlanta"), "Atlanta station no longer exist");
		UNIT_TEST_TRUE(sim.stationExists("South Bend"), "South Bend station still exists");

		sim.addStation("Atlanta");
		sim.addStation("South Bend");
		sim.connectStations("Atlanta", "South Bend", 14);
		sim.connectStations("South Bend", "Atlanta", 5);
		sim.connectStations("South Bend", "Atlanta", 8);

		sim.print();
		cout << endl;

		// tests #8 - #9
		UNIT_TEST_EQUAL(sim.connectionLength("South Bend", "Atlanta"), 8u, "Connection length SB->ATL is the latest assigned");
		UNIT_TEST_EQUAL(sim.connectionLength("Atlanta", "South Bend"), 14u, "Connection length ATL->SB is correct");

		sim.disconnectStations("South Bend", "Atlanta");

		sim.print();
		cout << endl;

		// test #10
		UNIT_TEST_TRUE(sim.stationsConnected("Atlanta", "South Bend"), "Despite overriding connections, ATL->SB are now disconnected");
	}

	// Part 2: tests for trains only
	void run_part2() {
		// Part 3: tests for trains only
		TrainSimulator sim;

		// add stations and connect them
		cout << "***Part 2: Total " << NUM_STAT << " stations, " << NUM_CONN << " connections" << endl << endl;

		for (uint i = 0; i < NUM_STAT; ++i)
			sim.addStation(stations[i]);
		for (uint i = 0; i < NUM_CONN; ++i)
			sim.connectStations(connections[i].from, connections[i].to, connections[i].dist);

		sim.print();
		cout << endl;

		// tests #11 - #13
		UNIT_TEST_TRUE(sim.stationExists("South Bend") && sim.stationExists("Atlanta") && sim.stationExists("Louisville"), "Some stations exist");
		UNIT_TEST_TRUE(sim.stationsConnected("Atlanta", "Buffalo") && sim.stationsConnected("Cleveland", "South Bend") && sim.stationsConnected("South Bend", "Cleveland"), "Some connections checked");
		UNIT_TEST_TRUE(sim.connectionLength("Cleveland", "Louisville") == 6u && sim.connectionLength("South Bend", "Cleveland") == 6u && sim.connectionLength("Chicago", "South Bend") == 1u, "Connection length check");

		// add trains
		cout << "***Part 2: Total trains " << NUM_TRAINS << endl << endl;

		for (uint i = 0; i < NUM_TRAINS; ++i)
			sim.addTrain(trains[i].name, trains[i].wagons, trains[i].station);

		sim.print();
		cout << endl;

		bool trainsExist = true;
		bool trainsTraveling = false;
		bool wagonsRight = true;
		bool stationedRight = true;
		for (uint i = 0; i < NUM_TRAINS; ++i) {
			if (!sim.trainExists(trains[i].name)) trainsExist = false;
			if (sim.trainTraveling(trains[i].name)) trainsTraveling = true;
			if (sim.numberWagons(trains[i].name) != trains[i].wagons) wagonsRight = false;
			if (sim.whereStationed(trains[i].name) != trains[i].station) stationedRight = false;
		}

		UNIT_TEST_TRUE(trainsExist, "Added trains should exist");
		UNIT_TEST_TRUE(!trainsTraveling, "No added trains should be traveling yet");
		UNIT_TEST_TRUE(wagonsRight, "Trains should have the original number of wagons");
		UNIT_TEST_TRUE(stationedRight, "All trains should be stationed in their originally specified stations");

		sim.removeTrain("Derrick");
		UNIT_TEST_TRUE(!sim.trainExists("Derrick"), "Train \"Derrick\" no longer exists");

		trainsExist = true;
		trainsTraveling = false;
		wagonsRight = true;
		stationedRight = true;
		for (uint i = 0; i < NUM_TRAINS; ++i) {
			if (trains[i].name == string("Derrick"))
				continue;
			if (!sim.trainExists(trains[i].name)) trainsExist = false;
			if (sim.trainTraveling(trains[i].name)) trainsTraveling = true;
			if (sim.numberWagons(trains[i].name) != trains[i].wagons) wagonsRight = false;
			if (sim.whereStationed(trains[i].name) != trains[i].station) stationedRight = false;
		}
		UNIT_TEST_TRUE(trainsExist && !trainsTraveling && wagonsRight && stationedRight, "Trains ok after Derrick removed");

		sim.addTrain("Derrick", 10u, "Louisville"); // add Derrick back
		UNIT_TEST_TRUE(sim.trainExists("Derrick"), "Train \"Derrick\" exists again");

		sim.addWagon("Tara");
		UNIT_TEST_EQUAL(sim.numberWagons("Tara"), 8u, "Train Tara has one more wagon");

		sim.removeWagon("Jimmy");
		sim.removeWagon("Jimmy");
		UNIT_TEST_EQUAL(sim.numberWagons("Jimmy"), 1u, "Train Jimmy lost two wagons");
	}

	// Part 3: combined tests for running simulation
	void run_part3() {
		TrainSimulator sim;
		// add stations and trains
		cout << "***Part 3: Same initial setup as Part 2" << endl << endl;
		for (uint i = 0; i < NUM_STAT; ++i)
			sim.addStation(stations[i]);
		for (uint i = 0; i < NUM_CONN; ++i)
			sim.connectStations(connections[i].from, connections[i].to, connections[i].dist);
		for (uint i = 0; i < NUM_TRAINS; ++i)
			sim.addTrain(trains[i].name, trains[i].wagons, trains[i].station);

		sim.departNextTrain("Cleveland", "South Bend"); // should be Johnny

		sim.print();
		cout << endl;

		UNIT_TEST_TRUE(sim.trainExists("Johnny"), "Departed train Johnny didn't disappear");
		UNIT_TEST_TRUE(sim.trainTraveling("Johnny"), "Johnny is indeed traveling");
		UNIT_TEST_EQUAL(sim.numberWagons("Johnny"), 58u, "Train Johnny has the same wagons");
		UNIT_TEST_EQUAL(sim.trainOrigin("Johnny"), string("Cleveland"), "Train Johnny departs from Cleveland");
		UNIT_TEST_EQUAL(sim.trainDestination("Johnny"), string("South Bend"), "Train Johnny is heading to South Bend");
		UNIT_TEST_EQUAL(sim.distanceTraveled("Johnny"), 0u, "Train Johnny has not moved yet");

		sim.step();
		UNIT_TEST_EQUAL(sim.distanceTraveled("Johnny"), 1u, "One step for Johnny");
		UNIT_TEST_EQUAL(sim.trainOrigin("Johnny"), string("Cleveland"), "Train Johnny is still traveling from Cleveland");
		UNIT_TEST_EQUAL(sim.trainDestination("Johnny"), string("South Bend"), "Train Johnny is still heading to South Bend");
		UNIT_TEST_EQUAL(sim.numberWagons("Johnny"), 58u, "Train Johnny has the same wagons");

		sim.step();
		UNIT_TEST_EQUAL(sim.distanceTraveled("Johnny"), 2u, "Another step for Johnny");
		sim.step();
		UNIT_TEST_EQUAL(sim.distanceTraveled("Johnny"), 3u, "Another step for Johnny");
		sim.step();
		UNIT_TEST_EQUAL(sim.distanceTraveled("Johnny"), 4u, "Another step for Johnny");
		sim.step();
		UNIT_TEST_TRUE(!sim.trainTraveling("Johnny"), "Johnny is no longer traveling");
		UNIT_TEST_EQUAL(sim.whereStationed("Johnny"), string("South Bend"), "Johnny is now stationed in South Bend");
		UNIT_TEST_EQUAL(sim.numberWagons("Johnny"), 58u, "Train Johnny has the same wagons");

		sim.departNextTrain("South Bend", "Cleveland"); // should be Johnny again
		sim.step();
		UNIT_TEST_TRUE(sim.trainTraveling("Johnny"), "Johnny is traveling again");
		UNIT_TEST_EQUAL(sim.distanceTraveled("Johnny"), 1u, "Johnny has traveled 1 step");

		UNIT_TEST_TRUE(sim.trainExists("Johnny"), "Therefore Johnny exist");
		sim.removeTrain("Johnny"); // train removal while moving
		UNIT_TEST_TRUE(!sim.trainExists("Johnny"), "And Johnny ceased to exist");
		sim.addTrain("Johnny", 33u, "Cleveland");
		UNIT_TEST_TRUE(sim.trainExists("Johnny"), "But Johnny is back");
		UNIT_TEST_EQUAL(sim.whereStationed("Johnny"), string("Cleveland"), "Johnny is in its native Cleveland");

		// more than 1 train in a railroad
		sim.departNextTrain("Detroit", "Cleveland");
		UNIT_TEST_TRUE(sim.trainTraveling("Rachael"), "Rachael departed");
		UNIT_TEST_EQUAL(sim.distanceTraveled("Rachael"), 0u, "Rachael has traveled 0 units");
		sim.departNextTrain("Detroit", "Cleveland");
		UNIT_TEST_TRUE(sim.trainTraveling("Harry"), "Harry departed");
		UNIT_TEST_EQUAL(sim.distanceTraveled("Harry"), 0u, "Harry has traveled 0 units");

		sim.step();
		sim.removeWagon("Rachael");
		sim.print();
		cout << endl;
		sim.step();

		UNIT_TEST_EQUAL(sim.whereStationed("Rachael"), string("Cleveland"), "Rachael is in Cleveland");
		UNIT_TEST_EQUAL(sim.numberWagons("Rachael"), 3u, "Rachael arrives with one less wagon");
		UNIT_TEST_EQUAL(sim.whereStationed("Harry"), string("Cleveland"), "Harry is in Cleveland");
		UNIT_TEST_EQUAL(sim.numberWagons("Harry"), 5u, "Harry arrives with same wagons");

		// restore previous state
		sim.removeTrain("Harry");
		sim.removeTrain("Rachael");
		sim.addTrain("Rachael", 4u, "Detroit");
		sim.addTrain("Harry", 5u, "Detroit");

		// all trains on the move!
		sim.departNextTrain("Atlanta", "South Bend");
		UNIT_TEST_TRUE(sim.trainTraveling("Jackie"), "Jackie departed");
		sim.departNextTrain("Atlanta", "Buffalo");
		UNIT_TEST_TRUE(sim.trainTraveling("Lukas"), "Lukas departed");
		sim.departNextTrain("Buffalo", "Cleveland");
		UNIT_TEST_TRUE(sim.trainTraveling("Charlie"), "Charlie departed");
		sim.departNextTrain("Chicago", "South Bend");
		UNIT_TEST_TRUE(sim.trainTraveling("Choo Choo"), "Choo Choo departed");
		sim.departNextTrain("Chicago", "South Bend");
		UNIT_TEST_TRUE(sim.trainTraveling("Jimmy"), "Jimmy departed");
		sim.departNextTrain("Cleveland", "South Bend");
		UNIT_TEST_TRUE(sim.trainTraveling("Alex"), "Alex departed");
		sim.departNextTrain("Cleveland", "Atlanta");
		UNIT_TEST_TRUE(sim.trainTraveling("Connie"), "Connie departed");
		sim.departNextTrain("Cleveland", "Louisville");
		UNIT_TEST_TRUE(sim.trainTraveling("Tara"), "Tara departed");
		sim.departNextTrain("Cleveland", "South Bend");
		UNIT_TEST_TRUE(sim.trainTraveling("Johnny"), "Johnny departed");
		sim.departNextTrain("Detroit", "Cleveland");
		UNIT_TEST_TRUE(sim.trainTraveling("Rachael"), "Rachael departed");
		sim.departNextTrain("Detroit", "Toronto");
		UNIT_TEST_TRUE(sim.trainTraveling("Harry"), "Harry departed");
		sim.departNextTrain("Louisville", "Atlanta");
		UNIT_TEST_TRUE(sim.trainTraveling("Maureen"), "Maureen departed");
		sim.departNextTrain("Louisville", "Chicago");
		UNIT_TEST_TRUE(sim.trainTraveling("Derrick"), "Derrick departed");
		sim.departNextTrain("Toronto", "Buffalo");
		UNIT_TEST_TRUE(sim.trainTraveling("Andy"), "Andy departed");

		sim.step();
		sim.step();
		sim.step();
		sim.step();
		sim.step();

		sim.print();
		cout << endl;

		UNIT_TEST_TRUE(!sim.trainTraveling("Choo Choo") && sim.whereStationed("Choo Choo")==string("South Bend"), "Choo Choo stationed in South Bend");
		UNIT_TEST_TRUE(!sim.trainTraveling("Jimmy") && sim.whereStationed("Jimmy")==string("South Bend"), "Jimmy stationed in South Bend");
		UNIT_TEST_TRUE(!sim.trainTraveling("Alex") && sim.whereStationed("Alex")==string("South Bend"), "Alex stationed in South Bend");
		UNIT_TEST_TRUE(!sim.trainTraveling("Johnny") && sim.whereStationed("Johnny")==string("South Bend"), "Johnny stationed in South Bend");
		UNIT_TEST_TRUE(!sim.trainTraveling("Rachael") && sim.whereStationed("Rachael")==string("Cleveland"), "Rachael stationed in Cleveland");
		UNIT_TEST_TRUE(!sim.trainTraveling("Maureen") && sim.whereStationed("Maureen")==string("Atlanta"), "Maureen stationed in Atlanta");

		UNIT_TEST_TRUE(sim.trainTraveling("Charlie") && sim.trainOrigin("Charlie")==string("Buffalo") && sim.trainDestination("Charlie")==string("Cleveland")
						&& sim.distanceTraveled("Charlie")==5u && sim.numberWagons("Charlie")==6u, "Charlie traveling with correct state");
		UNIT_TEST_TRUE(sim.trainTraveling("Connie") && sim.trainOrigin("Connie")==string("Cleveland") && sim.trainDestination("Connie")==string("Atlanta")
						&& sim.distanceTraveled("Connie")==5u && sim.numberWagons("Connie")==4u, "Connie traveling with correct state");
		UNIT_TEST_TRUE(sim.trainTraveling("Tara") && sim.trainOrigin("Tara")==string("Cleveland") && sim.trainDestination("Tara")==string("Louisville")
						&& sim.distanceTraveled("Tara")==5u && sim.numberWagons("Tara")==7u, "Tara traveling with correct state");
	}
};

int main(int argc, char **argv) {
	TrainSimTester().run("TrainSimulator's comprehensive test", argc, argv);
	return 0;
}
