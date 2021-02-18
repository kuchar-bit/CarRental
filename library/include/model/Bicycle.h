//
// Created by student on 4/29/20.
//

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H
#include <string>
#include <sstream>
#include <iostream>
#include "model/Vehicle.h"

class Bicycle : public Vehicle
{
public:
    Bicycle(const std::string &plateNumber, const unsigned int &basePrice);
    virtual ~Bicycle();
    std::string getVehicleInfo() override;
    unsigned int getActualRentalPrice() override;

};


#endif //CARRENTAL_BICYCLE_H
