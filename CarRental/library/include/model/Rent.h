//
// Created by student on 4/10/20.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "Client.h"
#include "Vehicle.h"
#include <string>
#include <iostream>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time.hpp>
#include <sstream>


namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


class Rent
{
private:
    unsigned int ID;
    Vehicle *vehicle;
    Client *client;
    pt::ptime beginTime;
    pt::ptime endTime;
    double rentCost=0;

public:

    //konstruktor z listą inicjalizacyjna
    Rent(const unsigned int &ID, Vehicle *vehicle, Client *client, pt::ptime &beginTime);

    // destruktor
    virtual ~Rent();

    // metody/operacje
    std::string getRentInfo();
    int getRentDays();
    void endRent(pt::ptime&);

    // gettery/settery
    const unsigned int &get_ID() const;
    const pt::ptime &get_beginTime() const;
    const pt::ptime &get_endTime() const;
    Vehicle *get_vehicle() const;
    Client *get_client() const;
    double get_rentCost() const;

};


#endif //CARRENTAL_RENT_H
