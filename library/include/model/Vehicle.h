//
// Created by student on 4/10/20.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <string>
#include "repositories/VehicleRepository.h"
#include <string>
#include <sstream>
#include <iostream>
#include <list>



class Vehicle
{
protected:
    std::string plateNumber;
    unsigned int basePrice;
    bool isArchive;


public:

    //konstruktor z listą inicjalizacyjna
    Vehicle(const std::string &plateNumber, const unsigned int &basePrice);

    // destruktor
    virtual ~Vehicle();

    // metody/operacje
    virtual std::string getVehicleInfo()=0;
    virtual unsigned int getActualRentalPrice()=0;

    // gettery/settery
    virtual const std::string &get_plateNumber() const;
    virtual const unsigned int &get_basePrice() const;
    virtual const bool &get_isArchive() const;

    virtual void set_plateNumber(const std::string &pN);
    virtual void set_basePrice(const unsigned int &bP);
    virtual void set_isArchive(const bool &archived);



};


#endif //CARRENTAL_VEHICLE_H
