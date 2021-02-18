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


Client::Client(const string &fN, const string &lN, const string &pID, Address *adres) : firstName(fN), lastName(lN), personalID(pID), adres(adres)
{
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
     sout << adres->getAddressInfo() << endl;
     return sout.str();
}


std::string Client::getFullClientInfo()
{
    ostringstream sout;
    sout << getClientInfo() << endl;
    sout << getCurrentRentsInfo() << endl;
    return sout.str();
}


const string &Client::get_firstName() const
{
    return firstName;
}

const string &Client::get_lastName() const
{
    return lastName;
}

const string &Client::get_personalID() const
{
    return personalID;
}

Address *Client::get_adres() const
{
    return adres;
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

void Client::set_adres(Address *adres)
{
    if (adres==nullptr)
    {
        cout <<"Nie mozna ustawic pustego wskaznika dla pola adres." << endl;
    }
    else{
        Client::adres=adres;
    }
}


void Client::addRent(Rent *rent)
{
    currentRents.push_back(rent);
}


void Client::delRent(Rent *rent)
{
//    currentRents.erase(remove(currentRents.begin(), currentRents.end(), rent), currentRents.end());
}

const std::vector<Rent *> &Client::getCurrentRents() const {
    return currentRents;
}

const std::string Client::getCurrentRentsInfo() const {
    ostringstream sout;

    for (int i=0;i<currentRents.size();i++)
        sout << currentRents[i]->getRentInfo();
    return sout.str();
}



