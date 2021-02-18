//
// Created by student on 5/1/20.
//

#include "managers/RentManager.h"

using namespace std;

RentPtr RentManager::makeRent(unsigned int ID, ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime)
{
    list<RentPtr> ClientRents=findAll(currentRentsList, [client](RentPtr r){return r->get_client()==client;});
    RentPtr VehicleCheck=find(ID);

    if (ClientRents.size()==client->get_maxVehicles() || VehicleCheck!=nullptr)
    {
        return nullptr;
    }

    else
        {
        RentPtr newRent(new Rent(ID, vehicle, client, beginTime));
        add(newRent);
        return newRent;
    }
}


void RentManager::cancelRent(unsigned int ID)
{
    RentPtr vehicleCheck=find(ID);
    pt::ptime endTime=pt::not_a_date_time;
    if (vehicleCheck!=nullptr)
    {
        vehicleCheck->endRent(endTime);
        for (list<RentPtr>::const_iterator i=currentRentsList->rentRepositoryList.begin(); i!=currentRentsList->rentRepositoryList.end(); i++)
        {
            if((*i)->get_vehicle()->get_plateNumber()==vehicleCheck->get_vehicle()->get_plateNumber())
                archiveRentsList->rentRepositoryList.splice(archiveRentsList->rentRepositoryList.end(),currentRentsList->rentRepositoryList, i);
            break;
        }
        checkClientRentBalance(vehicleCheck->get_client());
    }

    else
    {
        cout << "Nie mozna zakonczyc wypozyczenia. Pojazd nie jest wypozyczony"<<endl;
    }
}


void RentManager::checkClientRentBalance(ClientPtr client)
{
    list<RentPtr> clientRents=findAll(archiveRentsList, [client](RentPtr r){return r->get_client()==client;});
    int balance=0;
    for (list<RentPtr>::const_iterator iter=clientRents.begin(); iter!=clientRents.end(); iter++)
    {
        balance=balance+(*iter)->get_rentCost();
    }
    changeClientType(client, balance);
}


void RentManager::changeClientType(ClientPtr client, int sum) {
    ClientTypePtr bronze(new ClientBronze());
    ClientTypePtr silver(new ClientSilver());
    ClientTypePtr gold(new ClientGold());
    ClientTypePtr platinum(new ClientPlatinum());
    ClientTypePtr diamond(new ClientDiamond());

    if (client->get_maxVehicles()==1)
    {
        if(sum>=100)
        {
            client->set_clientType(bronze);
        }
    }
    else if (client->get_maxVehicles()==2)
    {
        if(sum>=200)
        {
            client->set_clientType(silver);
        }
    }
    else if (client->get_maxVehicles()==3)
    {
        if(sum>=400)
        {
            client->set_clientType(gold);
        }
    }
    else if (client->get_maxVehicles()==4)
    {
        if(sum>=800)
        {
            client->set_clientType(platinum);
        }
    }
    else if (client->get_maxVehicles()==5)
    {
        if(sum>=1600)
        {
            client->set_clientType(diamond);
        }
    }
}


list<RentPtr> RentManager::getAllClientRents(ClientPtr client)
{
    list<RentPtr> clientArchiveRents=findAll(archiveRentsList, [client](RentPtr rent){return rent->get_client()==client;});
    list<RentPtr> clientTotalRents=findAll(currentRentsList, [client](RentPtr rent){return rent->get_client()==client;});
    clientTotalRents.splice(clientTotalRents.end(),clientArchiveRents);
    return clientTotalRents;
}


const RentRepositoryPtr &RentManager::getCurrentRents() const
{
    return currentRentsList;
}


const RentRepositoryPtr &RentManager::getArchiveRents() const
{
    return archiveRentsList;
}

std::list<RentPtr> &RentManager::getCurrentRentsList()
{
    return currentRentsList->rentRepositoryList;
}


std::list<RentPtr> &RentManager::getArchiveRentsList()
{
    return archiveRentsList->rentRepositoryList;
}


void RentManager::add(RentPtr r)
{
    currentRentsList->rentRepositoryList.push_back(r);
}


std::list<RentPtr> RentManager::findAll(RentRepositoryPtr rentRepository, RentPredicate wsk)
{
    list<RentPtr> Searched;
    for (list<RentPtr>::const_iterator iter = rentRepository->rentRepositoryList.begin(); iter != rentRepository->rentRepositoryList.end(); iter++)
    {
        if(wsk(*iter))
        {
            Searched.push_back(*iter);
        }
    }

    return Searched;
}


RentPtr RentManager::find(const unsigned int idWypozyczenia)
{
    for (list<RentPtr>::const_iterator iter = currentRentsList->rentRepositoryList.begin(); iter != currentRentsList->rentRepositoryList.end(); iter++)
    {
        if ((*iter)->get_ID()==idWypozyczenia)
        {
            return (*iter);
        }
    }

    return nullptr;
}


std::string RentManager::report(RentRepositoryPtr rentRepository)
{
    ostringstream sout;
    sout << endl;
    for (list<RentPtr>::const_iterator iter = rentRepository->rentRepositoryList.begin(); iter != rentRepository->rentRepositoryList.end(); iter++)
    {
        sout << (*iter)->getRentInfo() << endl;
        sout << endl;
    }
    return sout.str();
}


int RentManager::size()
{
    return currentRentsList->rentRepositoryList.size();
}


