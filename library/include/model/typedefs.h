//
// Created by student on 5/6/20.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H
#include <functional>
#include <memory>

class Client;
class Vehicle;
class Moped;
class Bicycle;
class Car;
class Rent;
class Address;
class RentRepository;
class VehicleRepository;
class ClientRepository;
class ClientType;
class ClientManager;
class VehicleManager;
class RentManager;


typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Moped> MopedPtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Address> AddressPtr ;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;
typedef std::shared_ptr<RentRepository> RentRepositoryPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<VehicleManager> VehicleManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;
typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;
typedef std::function<bool(VehiclePtr)> VehiclePredicate;


#endif //CARRENTAL_TYPEDEFS_H
