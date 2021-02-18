#include "utils.h"

using namespace std;

void Wypelnij(ClientManagerPtr clientManager, VehicleManagerPtr vehicleManager, RentManagerPtr rentManager)
{
    AddressPtr adres1(new Address("Warszawa", "ulica", "2"));
    AddressPtr adres2(new Address("Wroclaw", "aleja", "3"));

    clientManager->registerClient("Szymon", "Blazynski", "2134125", adres2);

    vehicleManager->registerCar("WWE2345", 500, 8000, Car::E);
    vehicleManager->registerMoped("co", 20, 5000);

    pt::ptime testTime = pt::not_a_date_time;

    rentManager->makeRent(1, clientManager->getClient("2321455"), vehicleManager->getVehicle("WWE2345"), testTime);
    rentManager->makeRent(2, clientManager->getClient("2134125"), vehicleManager->getVehicle("co"), testTime);

}