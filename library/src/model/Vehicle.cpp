//
// Created by student on 4/10/20.
//

#include <iostream>
#include "model/Vehicle.h"
#include <sstream>

using namespace std;

Vehicle::Vehicle(const string &pN, const unsigned int &bP) : plateNumber(pN), basePrice(bP)
{
}

Vehicle::~Vehicle()
{
}


std::string Vehicle::getVehicleInfo()
{
    ostringstream sout;
    sout << "Numer rejestracyjny pojazdu: " << Vehicle::plateNumber << "  Cena za 1 dobe wypozyczenia: " << Vehicle::basePrice << endl;
    return sout.str();
}

const std::string &Vehicle::get_plateNumber() const {
    return plateNumber;
}

const unsigned int &Vehicle::get_basePrice() const {
    return basePrice;
}


void Vehicle::set_plateNumber(const string &pN)
{
    if (pN=="")
    {
        cout << "Anulowano opcje zmiany numeru rejestracyjnego pojazdu. " << endl;
    }
    else
    {
        Vehicle::plateNumber = pN;
        cout << "Zmieniono numer rejestracyjny pojazdu na: " << plateNumber << endl;
    }

}

void Vehicle::set_basePrice(const unsigned int &bP)
{
    Vehicle::basePrice = bP;
    cout << "Zmieniono cenę za 1 dobe wypozyczenia na: " << basePrice << endl;
}


void Vehicle::set_isArchive(const bool &archived)
{
    Vehicle::isArchive=archived;
}


const bool &Vehicle::get_isArchive() const
{
    return Vehicle::isArchive;
}


