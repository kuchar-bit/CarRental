//
// Created by student on 27.03.2020.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include <string>
#include <vector>
#include <iostream>
#include "Address.h"

//deklaracja zapowiadajaca
class Address;
class Rent;

class Client{
private:
    std::string firstName;
    std::string lastName;
    std::string const personalID;
    Address *adres;
    std::vector<Rent*> currentRents;


public:

    //konstruktor z listą inicjalizacyjna
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, Address *adres);

    // destruktor
    virtual ~Client();

    // metody/operacje
    std::string getClientInfo();
    std::string getFullClientInfo();
    void addRent(Rent *rent);
    void delRent(Rent *rent);

    // gettery/settery
    const std::string &get_firstName() const;
    const std::string &get_lastName() const;
    const std::string &get_personalID() const;
    Address *get_adres() const;
    const std::vector<Rent *> &getCurrentRents() const;
    const std::string getCurrentRentsInfo() const;
    void set_firstName(const std::string &I);
    void set_lastName(const std::string &J);
    void set_adres(Address *adres);

};


#endif //CARRENTAL_CLIENT_H
