//
// Created by student on 4/30/20.
//

#include "repositories/ClientRepository.h"

using namespace std;

ClientRepository::ClientRepository()
{
}


ClientRepository::~ClientRepository()
{
    for (list<ClientPtr>::iterator iter = clientRepositoryList.begin(); iter != clientRepositoryList.end(); iter++)
    {
        (*iter)=nullptr;
    }
}


