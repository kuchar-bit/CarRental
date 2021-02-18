//
// Created by student on 5/1/20.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H


class ClientType
{
protected:
    int maxVehicles;

public:
    ClientType();
    virtual ~ClientType();
    virtual unsigned long int getMaxVehicles() const=0;
    virtual double applyDiscount(int &price)=0;

};


#endif //CARRENTAL_CLIENTTYPE_H
