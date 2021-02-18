//
// Created by student on 4/30/20.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H

#include "model/Client.h"
#include "model/Vehicle.h"
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <memory>
#include "model/typedefs.h"

class Vehicle;

typedef std::shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository
{
private:
    friend class VehicleManager;
    std::list<VehiclePtr> vehicleRepositoryList;

public:
    VehicleRepository();
    virtual ~VehicleRepository();

};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
