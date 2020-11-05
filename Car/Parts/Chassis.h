#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>
#include "Car/Parts/DepartmentOutput.h"
#include "Car/Car.h"

using namespace std;


class Chassis : public DepartmentOutput {
public:
    Chassis();

    Chassis *cpy();

    void removePart(string part);

    int getSpeed();

    Car *clone();

};

#endif
