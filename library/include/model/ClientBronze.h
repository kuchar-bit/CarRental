//
// Created by student on 5/2/20.
//

#ifndef CARRENTAL_CLIENTBRONZE_H
#define CARRENTAL_CLIENTBRONZE_H


#include "ClientType.h"

class ClientBronze : public ClientType{

public:
    unsigned long int getMaxVehicles() const override;
    double applyDiscount(int &price) override;

};


#endif //CARRENTAL_CLIENTBRONZE_H
