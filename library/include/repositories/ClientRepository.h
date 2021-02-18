//
// Created by student on 4/30/20.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include "model/Client.h"
#include "model/Vehicle.h"
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <memory>
#include "model/typedefs.h"

class Client;

class ClientRepository
{
private:
    friend class ClientManager;
    std::list<ClientPtr> clientRepositoryList;

public:
    ClientRepository();
    virtual ~ClientRepository();


};
#endif //CARRENTAL_CLIENTREPOSITORY_H
