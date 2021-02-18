//
// Created by student on 5/1/20.
//

#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H

#include <model/Rent.h>
#include <repositories/RentRepository.h>
#include <iostream>


class RentManager{
private:
    RentRepositoryPtr currentRentsList=std::make_shared<RentRepository>();
    RentRepositoryPtr archiveRentsList=std::make_shared<RentRepository>();

public:
    const RentRepositoryPtr &getCurrentRents() const;
    const RentRepositoryPtr &getArchiveRents() const;
    std::list<RentPtr> &getCurrentRentsList();
    std::list<RentPtr> &getArchiveRentsList();
    RentPtr makeRent(unsigned int ID, ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime);
    void cancelRent(unsigned int ID);
    void checkClientRentBalance(ClientPtr client);
    void changeClientType(ClientPtr client, int sum);
    std::list<RentPtr> getAllClientRents(ClientPtr client);
    void add(RentPtr r);
    std::list<RentPtr> findAll(RentRepositoryPtr rentRepository, RentPredicate wsk);
    RentPtr find(const unsigned int idWypozyczenia);
    std::string report(RentRepositoryPtr rentRepository);
    int size();
};


#endif //CARRENTAL_RENTMANAGER_H
