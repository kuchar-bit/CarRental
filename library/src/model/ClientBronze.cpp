//
// Created by student on 5/2/20.
//

#include "model/ClientBronze.h"

unsigned long int ClientBronze::getMaxVehicles() const
{
    return 2;
}

double ClientBronze::applyDiscount(int &price)
{
    return price-3;
}
