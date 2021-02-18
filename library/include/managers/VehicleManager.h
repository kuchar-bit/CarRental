//
// Created by student on 5/1/20.
//

#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H

#include <model/Vehicle.h>
#include <repositories/VehicleRepository.h>
#include <model/Car.h>
#include <model/typedefs.h>
#include <model/Bicycle.h>
#include <model/Moped.h>

class VehicleManager{
private:
    VehicleRepositoryPtr vehicleManagerRepositoryList=std::make_shared<VehicleRepository>();

public:
    VehiclePtr registerBicycle(std::string plateNumber, int basePrice);
    VehiclePtr registerMoped(std::string plateNumber, int basePrice, int engineDisplacement);
    VehiclePtr registerCar(std::string plateNumber, int basePrice, int engineDisplacement, Car::segmentType segmentType);
    void unregisterVehicle(VehiclePtr vehicle);
    VehiclePtr getVehicle(std::string plateNumber);

    void add(VehiclePtr);
    std::list<VehiclePtr> findAll(VehiclePredicate);
    VehiclePtr find(const std::string nr_rejestracyjny);
    std::string report();
    unsigned int size();

};


#endif //CARRENTAL_VEHICLEMANAGER_H
