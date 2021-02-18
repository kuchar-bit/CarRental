#include <boost/test/unit_test.hpp>

using namespace std;

#include "model/Vehicle.h"
#include "model/Car.h"
#include "model/Moped.h"
#include "model/Bicycle.h"

struct VehicleTest{
    const std::string testPlateNumber="KLW69";
    const std::string newPlateNumber="WKW12";
    const unsigned int testBasePrice=300;
    const unsigned int newBasePrice=400;
    const int testEngineDisplacement=5000;
    const int newEngineDisplacement=6000;
    Car::segmentType testSegment=Car::B;

    VehicleTest()
    {
    }

    ~VehicleTest()
    {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, VehicleTest)

    BOOST_AUTO_TEST_CASE(VehicleConstructorTest)
    {
        Car* BMW_E36=new Car(testPlateNumber, testBasePrice, 8000, Car::B);
        BOOST_TEST_CHECK(BMW_E36->get_basePrice()==testBasePrice);
        BOOST_TEST_CHECK(BMW_E36->get_plateNumber()==testPlateNumber);
    }
    BOOST_AUTO_TEST_CASE(SetBasePriceTest)
    {
        Car* BMW_E36=new Car(testPlateNumber, testBasePrice, 8000, Car::B);
        BMW_E36->set_basePrice(newBasePrice);
        BOOST_TEST_CHECK(BMW_E36->get_basePrice()==newBasePrice);
    }
    BOOST_AUTO_TEST_CASE(SetPlateNumberPositiveTest)
    {
        Car* BMW_E36=new Car(testPlateNumber, testBasePrice, 8000, Car::B);
        BMW_E36->set_plateNumber(newPlateNumber);
        BOOST_TEST_CHECK(BMW_E36->get_plateNumber()==newPlateNumber);
    }
    BOOST_AUTO_TEST_CASE(SetPlateNumberNegativeTest)
    {
        Car* BMW_E36=new Car(testPlateNumber, testBasePrice, 8000, Car::B);
        BMW_E36->set_plateNumber("");
        BOOST_TEST_CHECK(BMW_E36->get_plateNumber()==testPlateNumber);
    }
    BOOST_AUTO_TEST_CASE(SetEngineDisplacementTest)
    {
        Car* BMW_E36=new Car(testPlateNumber, testBasePrice,8000,Car::A);
        BMW_E36->set_engineDisplacement(newEngineDisplacement);
        BOOST_TEST_CHECK(BMW_E36->get_engineDisplacement()==newEngineDisplacement);
        delete BMW_E36;
    }
    BOOST_AUTO_TEST_CASE(BicycleRentalPriceTest)
    {
        Bicycle* rower=new Bicycle(testPlateNumber, testBasePrice);
        BOOST_TEST_CHECK(rower->getActualRentalPrice()==testBasePrice);
        delete rower;
    }
    BOOST_AUTO_TEST_CASE(MopedRentalPriceTest)
    {
        Moped* motorower= new Moped(testPlateNumber, testBasePrice,2500);
        BOOST_TEST_CHECK(motorower->getActualRentalPrice()==450);
        delete motorower;
    }
    BOOST_AUTO_TEST_CASE(CarRentalPriceTest)
    {
        Car* BMW_E36=new Car(testPlateNumber, testBasePrice, 8000, Car::E);
        BOOST_TEST_CHECK(BMW_E36->getActualRentalPrice()==675);
        delete BMW_E36;
    }
    BOOST_AUTO_TEST_CASE(CarRentalPriceInheritanceTest)
    {
        Car *BMW_E36 = new Car(testPlateNumber, testBasePrice, 8000, Car::E);
        BOOST_TEST_CHECK(BMW_E36->getActualRentalPrice() == 675);
        delete BMW_E36;
    }

BOOST_AUTO_TEST_SUITE_END()

