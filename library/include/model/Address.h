//
// Created by student on 4/6/20.
//

#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H
#include <string>
#include "model/typedefs.h"


class Address {
private:
    mutable std::string cityName;
    mutable std::string streetName;
    mutable std::string streetNumber;

public:

    //konstruktor z listą inicjalizacyjna
    Address(const std::string &cityName, const std::string &streetName, const std::string &streetNumber);

    // destruktor
    virtual ~Address();

    // metody/operacje
    std::string getAddressInfo();

    // gettery/settery
    const std::string &get_cityName() const;
    const std::string &get_streetName() const;
    const std::string &get_streetNumber() const;
    //void set_cityName(const std::string &C);
    //void set_streetName(const std::string &S);
    //void set_streetNumber(const std::string &N);

};


#endif //CARRENTAL_ADDRESS_H
