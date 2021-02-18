//
// Created by student on 27.03.2020.
//

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include <sstream>

class Rent;

using namespace std;


Client::Client(const string &fN, const string &lN, const string &pID,  AddressPtr address) : firstName(fN), lastName(lN), personalID(pID), address(address)
{
    clientType=std::make_shared<ClientDefault>();
}

Client::~Client()
{
}

string Client::getClientInfo()
{
     ostringstream sout;
     sout << endl;
     sout << "Informacje o kliencie: " << endl;
     sout << "Imie: " << Client::firstName << "  Nazwisko: " << Client::lastName << "  Pesel: " << Client::personalID << endl;
     sout << address->getAddressInfo() << endl;
     return sout.str();
}


std::string Client::getFullClientInfo()
{
    ostringstream sout;
    sout << getClientInfo() << endl;
    return sout.str();
}


const string &Client::get_firstName() const
{
    return Client::firstName;
}

const string &Client::get_lastName() const
{
    return Client::lastName;
}

const string &Client::get_personalID() const
{
    return Client::personalID;
}

AddressPtr Client::get_adres() const
{
    return Client::address;
}


void Client::set_firstName(const string &I)
{
    if (I=="")
    {
        cout << "Anulowano opcje zmiany imienia. " << endl;
    }
    else
    {
        Client::firstName = I;
        cout << "Zmieniono imie obiektu na: " << firstName << endl;
    }

}

void Client::set_lastName(const string &J)
{
    if (J=="")
    {
        cout << "Anulowano opcje zmiany nazwiska. " << endl;
    }
    else
    {
        Client::lastName = J;
        cout << "Zmieniono nazwisko obiektu na: " << lastName << endl;
    }
}

void Client::set_adres(AddressPtr address)
{
    if (address==nullptr)
    {
        cout <<"Nie mozna ustawic pustego wskaznika dla pola adres." << endl;
    }
    else{
        Client::address=address;
    }
}


const ClientTypePtr &Client::get_clientType() const
{
    return Client::clientType;
}


void Client::set_clientType(const ClientTypePtr &clientType)
{
    Client::clientType=clientType;
}


const bool &Client::get_isArchive() const
{
    return Client::isArchive;
}


void Client::set_isArchive(const bool &archived)
{
    Client::isArchive=archived;
}


unsigned long int Client::get_maxVehicles() const
{
    return this->clientType->getMaxVehicles();
}
