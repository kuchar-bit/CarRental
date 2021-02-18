//
// Created by student on 5/2/20.
//

#include "model/ClientPlatinum.h"

unsigned long int  ClientPlatinum::getMaxVehicles() const
{
    return 5;
}

double ClientPlatinum::applyDiscount(int &price) {
    return price*0.10;
}
