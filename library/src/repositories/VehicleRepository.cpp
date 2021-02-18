//
// Created by student on 4/30/20.
//

#include "repositories/VehicleRepository.h"

using namespace std;


VehicleRepository::VehicleRepository()
{

}


VehicleRepository::~VehicleRepository()
{
    for (list<VehiclePtr>::iterator iter = vehicleRepositoryList.begin(); iter != vehicleRepositoryList.end(); iter++)
    {
        (*iter)=nullptr;
    }
}



