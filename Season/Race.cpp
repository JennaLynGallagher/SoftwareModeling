#include "Season/Race.h"
#include "Car/Car.h"
#include <cstlib>

Race::Race(int l, bool euro, int d, string n, int avgL) {
    european = euro;
    laps = l;
    date = d;
    name = n;
    numCars = 0;
    averageLapTime = avgL;
}

void Race::runRace() {
    for (int i = 0; i < numCars; i++) {
        cars[i]->clearRaceTime();
    }
    cout << "Starting race: " << name;
    for (int i = 0; i < laps; i++) {
        for (int j = 0; j < numCars; ++j) {
            int time = rand() % 50 + averageLapTime;
            cars[j]->addRaceTime();
        }
    }
    printLeaderBoard();
}

void Race::printLeaderBoard() {
    sortDrivers();
    for (int i = 0; i < numCars; i++) {
        cout << i << ":" << cars[i]->getDriverName() << endl;
    }
}

void Race::runQualifying() {
    for (int i = 0; i < numCars; i++) {
        cars[i]->clearRaceTime();
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < numCars; ++j) {
            int time = rand() % 20 + averageLapTime;
            cars[j]->addRaceTime();
        }
    }
    printLeaderBoard();
}

void Race::runFreePractice1() {
    for (int i = 0; i < numCars; i++) {
        cars[i]->clearRaceTime();
    }

    for (int j = 0; j < numCars; ++j) {
        int time = rand() % 80 + averageLapTime;
        cars[j]->addRaceTime();
    }
    printLeaderBoard();
}

void Race::pitStop() {
	// TODO - implement Race::pitStop
	throw "Not yet implemented";
}

int Race::getDate() {
    return date;
}

bool Race::isEuropean() {
    return european;
}


void Race::runFreePractice2() {
    for (int i = 0; i < numCars; i++) {
        cars[i]->clearRaceTime();
    }

    for (int j = 0; j < numCars; ++j) {

        int time = rand() % 60 + averageLapTime;
        cars[j]->addRaceTime();
    }
    printLeaderBoard();
}

void Race::runRaceWeekend(Car** c) {
    for (int i = 0; i < numCars; i++) {
        cars[i]->clearRaceTime();
    }
    cout << "Race weekend for race:" << name << " is starting" << endl;
    runFreePractice1();
    runFreePractice2();
    runQualifying();
    runRace();
    cout << "Race weekend for race:" << name << " has ended" << endl;

}

void setCars(Car **c, int num) {
    cars = c;
    numCars = num;
}

void sortDrivers() {

}


