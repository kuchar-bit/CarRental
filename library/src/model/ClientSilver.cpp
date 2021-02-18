//
// Created by student on 5/2/20.
//

#include "model/ClientSilver.h"

unsigned long int  ClientSilver::getMaxVehicles() const
{
    return 3;
}

double ClientSilver::applyDiscount(int &price)
{
    return price-6;
}
