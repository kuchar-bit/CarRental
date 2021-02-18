//
// Created by student on 4/29/20.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include "model/Rent.h"
#include "model/Vehicle.h"
#include <string>
#include <iostream>
#include <list>
#include <memory>
#include "model/typedefs.h"

class RentRepository
{
private:
    friend class RentManager;
    std::list<RentPtr> rentRepositoryList;

public:
    RentRepository();
    virtual ~RentRepository();

};

#endif //CARRENTAL_RENTREPOSITORY_H
