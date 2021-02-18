//
// Created by student on 5/2/20.
//

#ifndef CARRENTAL_CLIENTDEFAULT_H
#define CARRENTAL_CLIENTDEFAULT_H


#include "ClientType.h"

class ClientDefault : public ClientType{

public:
    unsigned long int getMaxVehicles() const override;
    double applyDiscount(int &price) override;

};


#endif //CARRENTAL_CLIENTDEFAULT_H
