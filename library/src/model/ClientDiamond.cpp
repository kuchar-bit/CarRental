//
// Created by student on 5/2/20.
//

#include "model/ClientDiamond.h"

unsigned long int  ClientDiamond::getMaxVehicles() const
{
    return 10;
}

double ClientDiamond::applyDiscount(int &price)
{
    if (price>=0 && price<=125)
    {
        return price*0.9;
    }
    else if (price>125 && price<=250)
    {
        return price*0.8;
    }
    else if (price>250 && price <=500)
    {
        return price*0.7;
    }
    else if (price>500)
    {
        return price*0.6;
    }
    else
    {
        return price;
    }
}
