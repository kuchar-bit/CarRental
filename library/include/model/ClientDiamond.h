//
// Created by student on 5/2/20.
//

#ifndef CARRENTAL_CLIENTDIAMOND_H
#define CARRENTAL_CLIENTDIAMOND_H


#include "ClientType.h"

class ClientDiamond : public ClientType{

public:
    unsigned long int getMaxVehicles() const override;
    double applyDiscount(int &price) override;

};


#endif //CARRENTAL_CLIENTDIAMOND_H
