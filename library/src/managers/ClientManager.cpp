//
// Created by student on 5/1/20.
//

#include "managers/ClientManager.h"

using namespace std;

ClientPtr ClientManager::registerClient(std::string firstName, std::string lastName,std::string personalID ,AddressPtr address)
{
    ClientPtr Check=find(personalID);
    if (Check != nullptr)
    {
        return Check;
    }
    else if (address == nullptr)
    {
        return nullptr;
    }
    else{
        ClientPtr newClient(new Client(firstName,lastName,personalID,address));
        add(newClient);
        return newClient;
    }
}


void ClientManager::unregisterClient(ClientPtr client)
{
    if (client->get_isArchive())
    {
        cout << "Klient zostal juz odrejestrowany"<<endl;
    }

    client->set_isArchive(true);
}


ClientPtr ClientManager::getClient(string personalID)
{
    return find(personalID);
}


void ClientManager::add(ClientPtr client)
{
    clientManagerRepositoryList->clientRepositoryList.push_back(client);
}


std::list<ClientPtr> ClientManager::findAll(ClientPredicate wsk)
{
    list<ClientPtr> Searched;
    for (list<ClientPtr>::const_iterator iter = clientManagerRepositoryList->clientRepositoryList.begin(); iter != clientManagerRepositoryList->clientRepositoryList.end(); iter++)
    {
        if(wsk(*iter))
        {
            Searched.push_back(*iter);
        }
    }

    return Searched;
}


ClientPtr ClientManager::find(const string pesel)
{
    for (list<ClientPtr>::const_iterator iter = clientManagerRepositoryList->clientRepositoryList.begin(); iter != clientManagerRepositoryList->clientRepositoryList.end(); iter++)
    {
        if ((*iter)->get_personalID()==pesel)
        {
            return (*iter);
        }
    }

    return nullptr;
}


std::string ClientManager::report()
{
    ostringstream sout;
    sout << endl;
    for (list<ClientPtr>::const_iterator iter = clientManagerRepositoryList->clientRepositoryList.begin(); iter != clientManagerRepositoryList->clientRepositoryList.end(); iter++)
    {
        sout << (*iter)->getClientInfo() << endl;
        sout << endl;
    }
    return sout.str();
}


unsigned int ClientManager::size()
{
    return clientManagerRepositoryList->clientRepositoryList.size();
}
