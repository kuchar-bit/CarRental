//
// Created by student on 4/10/20.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <string>



class Vehicle
{
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented=0;


public:

    //konstruktor z listą inicjalizacyjna
    Vehicle(const std::string &plateNumber, const unsigned int &basePrice);

    // destruktor
    virtual ~Vehicle();

    // metody/operacje
    std::string getVehicleInfo();
    bool isRented() const;

    // gettery/settery
    const std::string &get_plateNumber() const;
    const unsigned int &get_basePrice() const;
    const bool get_rented() const;

    void set_plateNumber(const std::string &pN);
    void set_basePrice(const unsigned int &bP);
    void set_rented(bool r);



};


#endif //CARRENTAL_VEHICLE_H
