//
// Created by student on 5/2/20.
//

#ifndef CARRENTAL_CLIENTSILVER_H
#define CARRENTAL_CLIENTSILVER_H


#include "ClientType.h"

class ClientSilver : public ClientType {

public:
    unsigned long int getMaxVehicles() const override;
    double applyDiscount(int &price) override;

};


#endif //CARRENTAL_CLIENTSILVER_H
