//
// Created by student on 5/1/20.
//

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H

#include <model/Client.h>
#include <repositories/ClientRepository.h>
#include <model/ClientType.h>

class ClientManager{
private:
    ClientRepositoryPtr clientManagerRepositoryList=std::make_shared<ClientRepository>();
public:
    ClientPtr registerClient(std::string firstName, std::string lastName,std::string personalID ,AddressPtr address);
    void unregisterClient(ClientPtr client);
    ClientPtr getClient(std::string personalID);
    void add(ClientPtr);
    std::list<ClientPtr> findAll(ClientPredicate);
    ClientPtr find(const std::string pesel);
    std::string report();
    unsigned int size();

};


#endif //CARRENTAL_CLIENTMANAGER_H
