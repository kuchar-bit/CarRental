//
// Created by student on 5/2/20.
//

#ifndef CARRENTAL_CLIENTPLATINUM_H
#define CARRENTAL_CLIENTPLATINUM_H


#include "ClientType.h"

class ClientPlatinum : public ClientType {

public:
    unsigned long int getMaxVehicles() const override;
    double applyDiscount(int &price) override;

};


#endif //CARRENTAL_CLIENTPLATINUM_H
