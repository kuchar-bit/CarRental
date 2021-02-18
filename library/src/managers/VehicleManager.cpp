//
// Created by student on 5/1/20.
//

#include "managers/VehicleManager.h"
#include <iostream>

using namespace std;


VehiclePtr VehicleManager::registerBicycle(string plateNumber, int basePrice)
{
    VehiclePtr Check=find(plateNumber);
    if (Check != nullptr)
    {
        return nullptr;
    }

    else{
        VehiclePtr newBicycle(new Bicycle(plateNumber, basePrice));
        add(newBicycle);
        return newBicycle;
    }
}


VehiclePtr VehicleManager::registerMoped(string plateNumber, int basePrice, int engineDisplacement)
{
    VehiclePtr Check=find(plateNumber);
    if (Check != nullptr)
    {
        return nullptr;
    }

    else {
        VehiclePtr newMoped(new Moped(plateNumber, basePrice,engineDisplacement));
        add(newMoped);
        return newMoped;
    }
}


VehiclePtr VehicleManager::registerCar(string plateNumber, int basePrice, int engineDisplacement, Car::segmentType segmentType)
{
    VehiclePtr repeatCheck=find(plateNumber);
    if (repeatCheck != nullptr)
    {
        return nullptr;
    }

    else {
        VehiclePtr newCar(new Car(plateNumber, basePrice,engineDisplacement,segmentType));
        add(newCar);
        return newCar;
    }

}


void VehicleManager::unregisterVehicle(VehiclePtr vehicle)
{
    if (vehicle->get_isArchive())
        cout << "Pojazd jest juz odrejestrowany"<<endl;
    else
        vehicle->set_isArchive(true);
}


VehiclePtr VehicleManager::getVehicle(string plateNumber)
{
    return find(plateNumber);
}


void VehicleManager::add(VehiclePtr vehicle)
{
    vehicleManagerRepositoryList->vehicleRepositoryList.push_back(vehicle);
}


std::list<VehiclePtr> VehicleManager::findAll(VehiclePredicate wsk)
{
    list<VehiclePtr> Searched;
    for (list<VehiclePtr>::const_iterator iter = vehicleManagerRepositoryList->vehicleRepositoryList.begin(); iter != vehicleManagerRepositoryList->vehicleRepositoryList.end(); iter++)
    {
        if(wsk(*iter))
        {
            Searched.push_back(*iter);
        }
    }

    return Searched;
}


VehiclePtr VehicleManager::find(const string nr_rejestracyjny)
{
    for (list<VehiclePtr>::const_iterator iter = vehicleManagerRepositoryList->vehicleRepositoryList.begin(); iter != vehicleManagerRepositoryList->vehicleRepositoryList.end(); iter++)
    {
        if ((*iter)->get_plateNumber()==nr_rejestracyjny)
        {
            return (*iter);
        }
    }

    return nullptr;
}


std::string VehicleManager::report()
{
    ostringstream sout;
    sout << endl;
    for (list<VehiclePtr>::const_iterator iter = vehicleManagerRepositoryList->vehicleRepositoryList.begin(); iter != vehicleManagerRepositoryList->vehicleRepositoryList.end(); iter++)
    {
        sout << (*iter)->getVehicleInfo() << endl;
        sout << endl;
    }
    return sout.str();
}


unsigned int VehicleManager::size()
{
    return vehicleManagerRepositoryList->vehicleRepositoryList.size();
}
