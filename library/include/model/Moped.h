//
// Created by student on 4/29/20.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H
#include "MotorVehicle.h"
#include <string>
#include <sstream>


class Moped : public MotorVehicle
{
public:
    Moped(const std::string &plateNumber, const unsigned int &basePrice, const int engineDisplacement);
    virtual ~Moped();
    std::string getVehicleInfo() override;
    unsigned int getActualRentalPrice() override;
};


#endif //CARRENTAL_MOPED_H
