//
// Created by student on 27.03.2020.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include <string>
#include <vector>
#include "repositories/ClientRepository.h"
#include <iostream>
#include "model/Address.h"
#include "model/ClientType.h"
#include "model/ClientDefault.h"
#include "model/ClientBronze.h"
#include "model/ClientSilver.h"
#include "model/ClientGold.h"
#include "model/ClientPlatinum.h"
#include "model/ClientDiamond.h"


//deklaracja zapowiadajaca
class Address;
class Rent;

class Client{
private:
    std::string firstName;
    std::string lastName;
    std::string const personalID;
    AddressPtr address;
    ClientTypePtr clientType;
    bool isArchive=false;



public:

    //konstruktor z listą inicjalizacyjna
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr address);

    // destruktor
    virtual ~Client();

    // metody/operacje
    std::string getClientInfo();
    std::string getFullClientInfo();

    // gettery/settery
    const std::string &get_firstName() const;
    const std::string &get_lastName() const;
    const std::string &get_personalID() const;
    AddressPtr get_adres() const;
    const ClientTypePtr &get_clientType() const;
    const bool &get_isArchive() const;
    unsigned long int  get_maxVehicles() const;
    void set_firstName(const std::string &I);
    void set_lastName(const std::string &J);
    void set_adres(AddressPtr address);
    void set_clientType(const ClientTypePtr &clientType);
    void set_isArchive(const bool &archived);

};


#endif //CARRENTAL_CLIENT_H
