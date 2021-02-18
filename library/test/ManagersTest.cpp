#include <boost/test/unit_test.hpp>
#include "utils.h"

using namespace std;

struct RepositoriesTestSuite{
    const std::string testFirstName = "Adam";
    const std::string testLastName = "Mitczak";
    const std::string testPersonalID = "324235";
    const std::string testPlateNumber = "WE566";
    const std::string testFirstNameV2 = "Jakub";
    const unsigned int testRentID = 5;
    const unsigned int testBasePrice = 200;
    pt::ptime testDefaultTime = pt::not_a_date_time;
    ClientPtr testClient;
    VehiclePtr testCar;
    AddressPtr testAddress;

    RepositoriesTestSuite()
    {
        testAddress=std::make_shared<Address>("Krakow","Elbladzka","60");
        testClient=std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress);
        testCar=std::make_shared<Car>(testPlateNumber,testBasePrice,3000,Car::D);
    }

    ~RepositoriesTestSuite()
    {
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteManager,RepositoriesTestSuite)


    BOOST_AUTO_TEST_CASE(ClientManagerFindAllTest) {
        ClientManagerPtr testClientManager(new ClientManager());
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        RentManagerPtr testRentManager(new RentManager());
        Wypelnij(testClientManager,testVehicleManager,testRentManager);
        std::list<ClientPtr> Searched = testClientManager->findAll([this](ClientPtr client) { return client->get_firstName() == testFirstNameV2;});
        BOOST_TEST_CHECK(Searched.front()->get_lastName() == "Jakub");
        auto i=std::next(Searched.begin(), 1);
        BOOST_TEST_CHECK((*i)->get_lastName()=="Morowski");
    }

    BOOST_AUTO_TEST_CASE(ClientManagerFindTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        RentManagerPtr testRentManager(new RentManager());
        Wypelnij(testClientManager,testVehicleManager,testRentManager);
        BOOST_TEST_CHECK(testClientManager->find("324235")->get_personalID()==testPersonalID);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerFindTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        RentManagerPtr testRentManager(new RentManager());
        Wypelnij(testClientManager,testVehicleManager,testRentManager);
        BOOST_TEST_CHECK(testVehicleManager->find("WE566")->get_plateNumber()==testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(RentManagerFindTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        RentManagerPtr testRentManager(new RentManager());
        Wypelnij(testClientManager,testVehicleManager,testRentManager);
        BOOST_TEST_CHECK(testRentManager->find(5)->get_ID()==testRentID);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerAddTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        testClientManager->add(testClient);
        BOOST_TEST_CHECK(testClientManager->find("324235")->get_firstName()==testFirstName);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerReportTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        testClientManager->add(testClient);
        BOOST_TEST_CHECK(testClientManager->report()==testClient->getClientInfo());
    }

    BOOST_AUTO_TEST_CASE(ClientManagerRegisterNewClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress)->getClientInfo()==testClient->getClientInfo());
    }

    BOOST_AUTO_TEST_CASE(ClientManagerSizeTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress);
        BOOST_TEST_CHECK(testClientManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerRegisterExistingClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress);
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress)==(testClientManager->find(testPersonalID)));
        BOOST_TEST_CHECK(testClientManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerRegisterNullAddressTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        BOOST_TEST_CHECK(testClientManager->registerClient(testFirstName,testLastName,testPersonalID,nullptr)==nullptr);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerUnregisterClientTest)
    {
        ClientManagerPtr testClientManager(new ClientManager());
        ClientPtr newClient=testClientManager->registerClient(testFirstName,testLastName,testPersonalID,testAddress);
        testClientManager->unregisterClient(newClient);
        BOOST_TEST_CHECK(newClient->get_isArchive());
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRegisterBicycleTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        BOOST_TEST_CHECK(testVehicleManager->registerBicycle(testPlateNumber,testBasePrice)->get_plateNumber()==testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerBicycleSizeTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        testVehicleManager->registerBicycle(testPlateNumber,testBasePrice);
        BOOST_TEST_CHECK(testVehicleManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRegisterMopedTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        BOOST_TEST_CHECK(testVehicleManager->registerMoped(testPlateNumber,testBasePrice,400)->get_plateNumber()==testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerMopedSizeTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        testVehicleManager->registerMoped(testPlateNumber,testBasePrice,400);
        BOOST_TEST_CHECK(testVehicleManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRegisterCarTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        BOOST_TEST_CHECK(testVehicleManager->registerCar(testPlateNumber,testBasePrice,400,Car::B)->get_plateNumber()==testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerCarSizeTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        testVehicleManager->registerCar(testPlateNumber,testBasePrice,400,Car::B);
        BOOST_TEST_CHECK(testVehicleManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRegisterVehicleNegativeTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        testVehicleManager->registerBicycle(testPlateNumber,testBasePrice);
        BOOST_TEST_CHECK(testVehicleManager->registerBicycle(testPlateNumber,testBasePrice)==nullptr);
        BOOST_TEST_CHECK(testVehicleManager->size()==1);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerUnregisterVehicleTest)
    {
        VehicleManagerPtr testVehicleManager(new VehicleManager());
        VehiclePtr newVehicle=testVehicleManager->registerBicycle(testPlateNumber,testBasePrice);
        testVehicleManager->unregisterVehicle(newVehicle);
        BOOST_TEST_CHECK(newVehicle->get_isArchive()==true);
    }

    BOOST_AUTO_TEST_CASE(RentManagerMakeRentPositiveTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        BOOST_TEST_CHECK(testRentManager->makeRent(1,testClient,testCar,testDefaultTime)->get_client()==testClient);
        BOOST_TEST_CHECK(testRentManager->getCurrentRentsList().size()==1);
    }

    BOOST_AUTO_TEST_CASE(RentManagerMakeRentOverTheMaxTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        VehiclePtr rower(new Bicycle("WE2427",20));
        testRentManager->makeRent(1,testClient,testCar,testDefaultTime);
        BOOST_TEST_CHECK(testRentManager->makeRent(2,testClient,rower,testDefaultTime)==nullptr);
        BOOST_TEST_CHECK(testRentManager->getCurrentRentsList().size()==1);
        BOOST_TEST_CHECK(testRentManager->getAllClientRents(testClient).size()==1);
    }

    BOOST_AUTO_TEST_CASE(RentManagerMakeRentAlreadyRentedTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        ClientManagerPtr testClientManager(new ClientManager());
        ClientPtr newClient(new Client("Lukasz","Janiszewski","Pesel",testAddress));
        testRentManager->makeRent(1,testClient,testCar,testDefaultTime);
        BOOST_TEST_CHECK(testRentManager->makeRent(2,newClient,testCar,testDefaultTime)==nullptr);
    }
    BOOST_AUTO_TEST_CASE(RentManagerCancelRentBasicTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        testRentManager->makeRent(1,testClient,testCar,testDefaultTime);
        testRentManager->cancelRent(1);
        BOOST_TEST_CHECK(testRentManager->getArchiveRentsList().size()==1);
        BOOST_TEST_CHECK(testRentManager->getCurrentRentsList().size()==0);
    }

    BOOST_AUTO_TEST_CASE(RentManagerReturnVehicleTypeChangeTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        pt::ptime time = pt::ptime(gr::date(2020, 5, 5), pt::hours(10) + pt::minutes(30) + pt::seconds(30));
        testRentManager->makeRent(1,testClient,testCar,time);
        testRentManager->cancelRent(1);
        BOOST_TEST_CHECK(testClient->get_maxVehicles()==2);
    }

    BOOST_AUTO_TEST_CASE(RentManagerultipleVehiclesBalanceCheckTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        ClientTypePtr bronze(new ClientBronze());
        testClient->set_clientType(bronze);
        VehiclePtr rower1(new Bicycle("ELBICYCLE",50));
        VehiclePtr rower2(new Bicycle("ELBICYCLE",40));
        pt::ptime time = pt::ptime(gr::date(2020, 5, 3), pt::hours(8) + pt::minutes(15) + pt::seconds(20));
        testRentManager->makeRent(1,testClient,rower1,time);
        testRentManager->makeRent(2,testClient,rower2,time);
        testRentManager->cancelRent(1);
        testRentManager->cancelRent(2);
        BOOST_TEST_CHECK(testClient->get_maxVehicles()==3);
    }

    BOOST_AUTO_TEST_CASE(RentManagerGetAllClientRentsTest)
    {
        RentManagerPtr testRentManager(new RentManager());
        ClientTypePtr gold(new ClientGold());
        testClient->set_clientType(gold);
        VehiclePtr rower1(new Bicycle("ELBICYCLE",50));
        VehiclePtr rower2(new Bicycle("ELBICYCLE",40));
        pt::ptime time = pt::ptime(gr::date(2020, 5, 5), pt::hours(7) + pt::minutes(15) + pt::seconds(20));
        RentPtr rent1=testRentManager->makeRent(1,testClient,rower1,time);
        RentPtr rent2=testRentManager->makeRent(2,testClient,rower2,time);
        testRentManager->cancelRent(1);
        std::list<RentPtr> testResult=testRentManager->getAllClientRents(testClient);
        BOOST_TEST_CHECK(testResult.front()==rent2);
        BOOST_TEST_CHECK(testResult.back()==rent1);
        BOOST_TEST_CHECK(testResult.size()==2);
    }

BOOST_AUTO_TEST_SUITE_END()