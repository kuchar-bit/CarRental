//
// Created by student on 5/2/20.
//

#ifndef CARRENTAL_CLIENTGOLD_H
#define CARRENTAL_CLIENTGOLD_H


#include "ClientType.h"

class ClientGold : public ClientType {

public:
    unsigned long int getMaxVehicles() const override;
    double applyDiscount(int &price) override;

};


#endif //CARRENTAL_CLIENTGOLD_H
