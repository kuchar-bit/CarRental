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

const bool Vehicle::get_rented() const
{
    if (rented==0)
    {
        cout << "Pojazd nie jest wypozyczony." << endl;
    }
    else if (rented==1)
    {
        cout << "Pojazd jest wypozyczony." << endl;
    }
    return rented;
}

bool Vehicle::isRented() const
{
    return rented;
}

void Vehicle::set_rented(bool r)
{
    if(r==1 || r==0 || r==true || r==false)
    {
        Vehicle::rented = r;
        cout << "Zmieniono status wypozyczenia pojazdu." << endl;
    }
    else
    {
        cout << "Nieprawidlowa wartosc statusu wypozyczenia pojazdu." << endl;
    }


}

