//
// Created by student on 4/6/20.
//

#include <iostream>
#include "model/Address.h"
#include <sstream>

using namespace std;

Address::Address(const string &cN, const string &sN, const string &sNb) : cityName(cN), streetName(sN), streetNumber(sNb)
{
}

Address::~Address()
{
}

string Address::getAddressInfo()
{
    ostringstream sout;
    sout << "Nazwa miasta: " << Address::cityName << "  Nazwa ulicy: " << Address::streetName << "  Numer ulicy: " << Address::streetNumber << endl;
    return sout.str();
}

const std::string &Address::get_cityName() const
{
    return cityName;
}

const std::string &Address::get_streetName() const
{
    return streetName;
}

const std::string &Address::get_streetNumber() const
{
    return streetNumber;
}

void Address::set_cityName(const std::string &C)
{
    if (C=="")
    {
        cout << "Anulowano opcje zmiany nazwy miasta. " << endl;
    }
    else
    {
        Address::cityName = C;
        cout << "Zmieniono nazwe miasta obiektu na: " << cityName << endl;
    }

}

void Address::set_streetName(const std::string &S)
{
    if (S=="")
    {
        cout << "Anulowano opcje zmiany nazwy ulicy. " << endl;
    }
    else
    {
        Address::streetName = S;
        cout << "Zmieniono nazwe ulicy obiektu na: " << streetName << endl;
    }

}

void Address::set_streetNumber(const std::string &N)
{
    if (N=="")
    {
        cout << "Anulowano opcje zmiany numeru ulicy. " << endl;
    }
    else
    {
        Address::streetNumber = N;
        cout << "Zmieniono numer ulicy obiektu na: " << streetNumber << endl;
    }

}
