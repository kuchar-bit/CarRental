#include <boost/test/unit_test.hpp>

using namespace std;

#include "model/Vehicle.h"

struct VehicleTest{
    const std::string testPlateNumber="KLW69";
    const std::string newPlateNumber="WKW12";
    const unsigned int testBasePrice=300;
    const unsigned int newBasePrice=400;

    VehicleTest()
    {

    }

    ~VehicleTest()
    {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, VehicleTest)

    BOOST_AUTO_TEST_CASE(VehicleConstructorTest) {
        Vehicle BMW_E36(testPlateNumber,testBasePrice);
        BOOST_TEST_CHECK(BMW_E36.get_basePrice()==testBasePrice);
        BOOST_TEST_CHECK(BMW_E36.get_plateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(!BMW_E36.isRented());
    }
    BOOST_AUTO_TEST_CASE(SetBasePriceTest)
    {
        Vehicle BMW_E36(testPlateNumber,testBasePrice);
        BMW_E36.set_basePrice(newBasePrice);
        BOOST_TEST_CHECK(BMW_E36.get_basePrice()==newBasePrice);
    }
    BOOST_AUTO_TEST_CASE(SetPlateNumberPositiveTest)
    {
        Vehicle BMW_E36(testPlateNumber,testBasePrice);
        BMW_E36.set_plateNumber(newPlateNumber);
        BOOST_TEST_CHECK(BMW_E36.get_plateNumber()==newPlateNumber);
    }
    BOOST_AUTO_TEST_CASE(SetPlateNumberNegativeTest)
    {
        Vehicle BMW_E36(testPlateNumber,testBasePrice);
        BMW_E36.set_plateNumber("");
        BOOST_TEST_CHECK(BMW_E36.get_plateNumber()==testPlateNumber);
    }
BOOST_AUTO_TEST_SUITE_END()

