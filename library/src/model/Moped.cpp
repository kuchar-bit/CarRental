//
// Created by student on 4/29/20.
//

#include "model/Moped.h"

using namespace std;

Moped::Moped(const std::string &plateNumber, const unsigned int &basePrice, const int engineDisplacement) : MotorVehicle(plateNumber, basePrice, engineDisplacement)
{
}

Moped::~Moped()
{
}

unsigned int Moped::getActualRentalPrice()
{
    if (engineDisplacement<1000)
    {
        basePrice=basePrice*1;
    }
    else if (engineDisplacement>=1000 && engineDisplacement<=2000)
    {
        switch(engineDisplacement)
        {
            case 1000:
                basePrice=basePrice*1.0;
                break;
            case 1200:
                basePrice=basePrice*1.1;
                break;
            case 1400:
                basePrice=basePrice*1.2;
                break;
            case 1600:
                basePrice=basePrice*1.3;
                break;
            case 1800:
                basePrice=basePrice*1.4;
                break;
            case 2000:
                basePrice=basePrice*1.5;
                break;
            default:
                basePrice=basePrice*1.0;
        }
    }
    else if (engineDisplacement>2000)
    {
        basePrice=basePrice*1.5;
    }
    return basePrice;
}

std::string Moped::getVehicleInfo()
{
    ostringstream sout;
    sout << endl;
    sout << "Informacje o pojezdzie: " << endl;
    sout << this->getVehicleInfo() << endl;
    sout << "Pojemnosc silnika: "<< engineDisplacement <<" cm3" << endl;
    return sout.str();
}
