//
// Created by student on 4/29/20.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H
#include "model/MotorVehicle.h"

class Car : public MotorVehicle
{
public:
    enum segmentType
    {
        A, B, C, D, E
    };

private:
    segmentType segment;

public:
    Car(const std::string &plateNumber, const unsigned int &basePrice, const int engineDisplacement, segmentType segment);
    virtual ~Car();
    std::string getVehicleInfo() override;
    unsigned int getActualRentalPrice() override;
    int get_engineDisplacement() const override;
    void set_engineDisplacement(int eD) override;
    segmentType getSegment() const;
    void setSegment(segmentType segment);


};


#endif //CARRENTAL_CAR_H
