// train_sim.cxx
//
// Author: Raul Santelices
// Contact: cse30331fa12_tas@listserv.nd.edu
//
// This is the file where you will implement your solution,
// other than whatever you add to train_sim.h and perhaps new files you create
//
// Course: CSE 30331, Fall 2012

#include "train_sim.h"

//#include <cassert>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
//using namespace boost;


// Convenient typedefs
typedef TrainSimulator::uint uint;
typedef TrainSimulator::Distance Distance;

// This exists only to compile this "skeleton" solution
static const string _emptyName = "";


// CONSTRUCTORS

// POSTCONDITION: The network is empty -- no stations and no trains.
//   Note 1: You shouldn't need to change this (except if you need to initialize something specifc to your solution
//   Note 2: This contructor is NOT GRADED
TrainSimulator::TrainSimulator() {
	//stationQueue["travel"] = queue<string>();
	//queueVector.push_back(queue<string>());
}


// SIMULATION ACTIONS

// POSTCONDITION: All traveling trains have moved 1 unit towards their respective destinations.
//                Trains that completed the distance of the connection stop traveling and become
//                stationed (by being enqueued) at the destination station.
void TrainSimulator::step() {

	for(uint i = 0; i < travelVector.size(); ++i) {
		//cout << it->first << endl;
		map<string, Train>::iterator pos = trainMap.find(travelVector[i]);

		// Find origin, destination, then check the connection length
		map <string, pair<string,string> >::const_iterator it = travelSpots.find(travelVector[i]);

		Distance length = connectionLength(trainOrigin(travelVector[i]), trainDestination(travelVector[i])); //Origin,destination
		pos->second.traveled++;

		if(pos->second.traveled == length) {
			// If the new distance traveled is greater than or equal to the length of the destination, add it to the new queue
			pos->second.traveled = 0;
			pos->second.station = trainDestination(travelVector[i]);

			
			travelVector.erase(find(travelVector.begin(), travelVector.end(), travelVector[i]));
			//stravelVector.resize(remove(travelVector.begin(), travelVector.end(), travelVector[i]) - travelVector.begin()); // Remove from Stations Vector
			stationQueue[trainDestination(travelVector[i])].push(travelVector[i]);
			//pos->second.station = trainOrigin(travelVector[i]);
		}
		//if(pos->traveled == it->se)
	}
}

// PRECONDITION: stationsConnected(fromStation, toStation) and there is at least one train stationed at 'fromStation'
// POSTCONDITION: The train at the front of the stationed queue in 'fromStation' leaves that queue and
//                enters the traveling queue for the connection to 'toStation' with initial traveled distance 0.
void TrainSimulator::departNextTrain(const string& fromStation, const string& toStation) {
	if(!stationQueue[fromStation].empty()) {
	string train = stationQueue[fromStation].front();
	stationQueue[fromStation].pop();

	//stationQueue["travel"].push(train);

	//stationQueue[toStation].push(train);

	travelQueueMap[toStation].push(train);
	travelSpots[train]= make_pair(fromStation, toStation);
	travelVector.push_back(train);
	map<string, Train>::iterator pos = trainMap.find(train);

	pos->second.station = toStation;
	}



}


// STATION CREATION, CONNECTIVITY, & REMOVAL


// POSTCONDITION: stationExists(name)
//  Note: If station 'name' already existed in the network, nothing changes -- its connections and
//        the status of incoming/stationed/outgoing trains remains the same.
void TrainSimulator::addStation(const string& name) {
	stations.push_back(name);
	//stationQueue.push_back(queue<Train>());
	stationQueue[name] = queue<string>();
	//cout << stations.size();
}

// PRECONDITION: stationExists(name)
// POSTCONDITION: !stationExists(name). All trains stationed at 'name' or traveling to 'name' were removed.
//                All trains traveling from 'name' automatically arrived (got stationed) at their destinations (enqueued in their travel from 'name').
//                All connections to and from station 'name' have been removed.
void TrainSimulator::removeStation(const string& name) {
	stations.resize(remove(stations.begin(), stations.end(), name) - stations.begin()); // Remove from Stations Vector
	
}

// PRECONDITION: stationExists(from) && stationExists(to) && distance > 0
// POSTCONDITION: A directed link (a railroad) of length 'distance' is created from station 'from' to station 'to'.
//                If a connection already existed from 'from' to 'to', it is replaced by this new connection and distance.
void TrainSimulator::connectStations(const string& from, const string& to, Distance distance) {
	//connectionMap[make_pair(from,to)] = distance;
	pair<string, string> connector (from, to);
	//connectionMap.insert(make_pair(connector, distance));
	connectionMap[connector] = distance;
	connectionVector.push_back(connector);

}

// PRECONDITION: stationsConnected(from, to)
// POSTCONDITION: !stationsConnected(from, to)
//                All trains traveling from 'from' to 'to' have automatically arrived to (got stationed at) their destinations.
//  Note: If the stations were not connected, there is no change to the state of the simulation.
void TrainSimulator::disconnectStations(const string& from, const string& to) {
	pair<string, string> connector (from, to);
	connectionVector.erase(find(connectionVector.begin(), connectionVector.end(), connector));
	//connectionVector.resize(remove(connectionVector.begin(), connectionVector.end(), connector) - connectionVector.begin()); // Remove from Stations Vector
	connectionMap.erase(connector);
}


// STATION-SPECIFIC QUERIES

// POSTCONDITION: Returned true if station 'name' is in the network (i.e., 'name' was added before and not removed since then).
//                Returned false otherwise
bool TrainSimulator::stationExists(const string& name) const {
	//vector<string>::InputIterator it = ;
	if(find(stations.begin(), stations.end(), name) == stations.end()) {
		return false;
	}

	else {
		return true;
	}
 	//return find(stations.begin(), stations.end(), name) != stations.end(); // *** replace this with your solution
}

// PRECONDITION: stationExists(from) && stationExists(to)
// POSTCONDITION: Returned true if station 'name' is in the network (i.e., 'name' was added before and not removed since then).
//                Returned false otherwise
bool TrainSimulator::stationsConnected(const string& from, const string& to) const {
	if (connectionMap.find(make_pair(from, to)) == connectionMap.end()) {
	//if (find(connectionVector.begin(), connectionVector.end(), make_pair(from, to)) == connectionVector.end()) {
		return false;
	}

	else { return true; } // *** replace this with your solution
}

// PRECONDITION: stationExists(from) && stationExists(to) && stationsConnected(from, to)
// POSTCONDITION: Returned distance 'distance' provided when connectStations(from, to, distance) was last called
Distance TrainSimulator::connectionLength(const string& from, const string& to) const {
	//cout << connectionMap[pair(from,to)] << endl;
	pair<string, string> connector (from, to);
	map<pair<string,string>, Distance>::const_iterator pos = connectionMap.find(connector);

	if(pos == connectionMap.end()) {
		return 0;
	}

	return pos->second; // Return connection distance between two connected stations
}


// TRAIN INSERTION, MODIFICATION, & REMOVAL

// PRECONDITION: wagons > 0 && stationExists(station)
// POSTCONDITION: trainExists(name) && numberWagons(name) == wagons && whereStationed(name) == station
//   Note 1: The train will be located in one and only one queue at a time (i.e., a "traveling-to" or "stationed" queue)
//   Note 2: If the train existed, the only effect was to update its number of wagons with parameter 'wagons'. Its queue position remains the same.
//   Note 3: A train will always have at least one wagon
void TrainSimulator::addTrain(const string& name, uint wagons, const string& station) {
	Train newTrain = Train(name, wagons, 0, station);

	stationQueue[station].push(name);
	trains.push_back(newTrain);
	//trainMap[name] = Train(name, wagons, 0);
	trainMap.insert(pair<string, Train> (name, newTrain));
}

// PRECONDITION: trainExists(name)
// POSTCONDITION: !trainExists(name)
//  Note: The train was removed from whatever queue (traveling or stationed) it was located
void TrainSimulator::removeTrain(const string& name) {
	map<string, Train>::iterator pos = trainMap.find(name); //Map the iterator to find the train
	trainMap.erase(pos);

	if(find(travelVector.begin(), travelVector.end(), name) != travelVector.end()) {
	travelVector.erase(find(travelVector.begin(), travelVector.end(), name));
	}
	//travelVector.resize(remove(travelVector.begin(), travelVector.end(), name) - travelVector.begin()); // Remove from Stations Vector


	//stationQueue[pos->second.station]

}

// PRECONDITION: trainExists(train) && numberWagons(train) > 0
// POSTCONDITION: numberWagons(train) was incremented by 1
void TrainSimulator::addWagon(const string& train) {
	map<string, Train>::iterator pos = trainMap.find(train);

	pos->second.wagons++;

	//stationQueue[pos->second.station] = pos;


}

// PRECONDITION: trainExists(train) && numberWagons(train) > 1
// POSTCONDITION: numberWagons(train) was decremented by 1
void TrainSimulator::removeWagon(const string& train) {
	map<string, Train>::iterator pos = trainMap.find(train);

	pos->second.wagons--;
	//stationQueue[pos->second.station] = pos;

}


// TRAIN-SPECIFIC QUERIES

// POSTCONDITION: Returned true if train 'name' is in the network (i.e., 'name' was added before and not removed since then).
//                Returned false otherwise
bool TrainSimulator::trainExists(const string& name) const {
	if(trainMap.find(name) == trainMap.end()) {
		return false;
	}

	else {
		return true;
	}
}

// PRECONDITION: trainExists(name)
// POSTCONDITION: Returned true if train 'name' is traveling from some station to another.
//                Returned false otherwise (i.e., the train is stationed at some station)
bool TrainSimulator::trainTraveling(const string& name) const {
	//map<string, Train>::const_iterator pos = trainMap.find(name);
	if(find(travelVector.begin(), travelVector.end(), name) == travelVector.end()) {
		return false;
	}

	else {
		return true;
	}
}

// PRECONDITION: trainExists(train)
// POSTCONDITION: Returned number > 0 of wagons currently in train 'train'.
uint TrainSimulator::numberWagons(const string& train) const {
	//Train tmpTrain = trainMap[train];
	map<string, Train>::const_iterator pos = trainMap.find(train);

	if(pos == trainMap.end()) {
		return 0;
	}

	return pos->second.wagons; // *** replace this with your solution
}

// PRECONDITION: !trainTraveling(train)
// POSTCONDITION: Returned name of station in which train is stationed.
const string& TrainSimulator::whereStationed(const string& train) const {
	map<string, Train>::const_iterator pos = trainMap.find(train);

	return pos->second.station; // *** replace this with your solution
}

// PRECONDITION: trainTraveling(train)
// POSTCONDITION: Returned name of station from which train is traveling.
const string& TrainSimulator::trainOrigin(const string& train) const {
	map <string, pair<string,string> >::const_iterator it = travelSpots.find(train);

	return it->second.first; // *** replace this with your solution
}

// PRECONDITION: trainTraveling(train)
// POSTCONDITION: Returned name of station to which train is traveling.
const string& TrainSimulator::trainDestination(const string& train) const {
	map <string, pair<string,string> >::const_iterator it = travelSpots.find(train);

	return it->second.second; // *** replace this with your solution
}

// PRECONDITION: trainTraveling(train)
// POSTCONDITION: Returned distance >= 0 traveled so far by the train.
Distance TrainSimulator::distanceTraveled(const string& train) const {
	map<string, Train>::const_iterator pos = trainMap.find(train);

	return pos->second.traveled; // *** replace this with your solution
}


// TRAIN NETWORK PRITING

// *** NOT GRADED; use it to help yourself visualize your solution
void TrainSimulator::print(ostream& outs /*= cout*/) const {
}
