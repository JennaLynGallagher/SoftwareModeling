#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>
#include "Car/Parts/DepartmentOutput.h"

using namespace std;

class Chassis: public DepartmentOutput {

public:
    Chassis(Car* c);

};

#endif