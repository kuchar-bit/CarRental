//
// Created by student on 5/2/20.
//

#include "model/ClientGold.h"

unsigned long int  ClientGold::getMaxVehicles() const
{
    return 4;
}

double ClientGold::applyDiscount(int &price)
{
    return price*0.95;
}
