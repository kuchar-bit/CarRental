//
// Created by student on 4/30/20.
//

#ifndef CARRENTAL_UTILS_H
#define CARRENTAL_UTILS_H

#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"
#include "model/Car.h"
#include "model/Bicycle.h"
#include "model/Vehicle.h"
#include "model/MotorVehicle.h"
#include "managers/ClientManager.h"
#include "managers/VehicleManager.h"
#include "managers/RentManager.h"

void Wypelnij(ClientManagerPtr, VehicleManagerPtr, RentManagerPtr);

#endif //CARRENTAL_UTILS_H
