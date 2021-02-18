//
// Created by student on 4/29/20.
//

#include "model/Car.h"

using namespace std;

Car::Car(const string &plateNumber, const unsigned int &basePrice, const int engineDisplacement, segmentType segment) : MotorVehicle(plateNumber, basePrice, engineDisplacement), segment(segment)
{
}

Car::~Car()
{
}

std::string Car::getVehicleInfo()
{
    ostringstream sout;
    sout << endl;
    sout << "Informacje o samochodzie: " << endl;
    sout << this->getVehicleInfo() << endl;
    switch (segment)
    {
        case A:
            sout<<"A";
            break;
        case B:
            sout<<"B";
            break;
        case C:
            sout<<"C";
            break;
        case D:
            sout<<"D";
            break;
        case E:
            sout<<"E";
            break;
    }
    sout << endl;
    sout << "Pojemnosc silnika: "<< engineDisplacement <<" cm3" << endl;
    return sout.str();
}

unsigned int Car::getActualRentalPrice()
{
    switch (segment)
    {
        case A:
            return ActualRentalPrice();
            break;
        case B:
            return 1.1*ActualRentalPrice();
            break;
        case C:
            return 1.2*ActualRentalPrice();
            break;
        case D:
            return 1.3*ActualRentalPrice();
            break;
        case E:
            return 1.5*ActualRentalPrice();
            break;
    }

    return ActualRentalPrice();
}

Car::segmentType Car::getSegment() const
{
    return segment;
}

void Car::setSegment(Car::segmentType segment)
{
    Car::segment = segment;
}

int Car::get_engineDisplacement() const
{
    return engineDisplacement;
}

void Car::set_engineDisplacement(int eD)
{
    engineDisplacement = eD;
}

