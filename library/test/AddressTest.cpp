#include <boost/test/unit_test.hpp>

using namespace std;

#include "model/Address.h"


BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    Address adres("Lodz", "Pilsudskiego", "36");

    BOOST_AUTO_TEST_CASE(AddressGetTest)
    {
        BOOST_TEST(adres.get_cityName()=="Lodz");
        BOOST_TEST(adres.get_streetName()=="Pilsudskiego");
        BOOST_TEST(adres.get_streetNumber()=="36");
    }

//    BOOST_AUTO_TEST_CASE(AddressSetTest)
//    {
//        adres.set_cityName("");
//        BOOST_TEST(adres.get_cityName()=="Lodz");
//        BOOST_TEST_WARN(adres.get_cityName()=="");
//        adres.set_streetName("");
//        BOOST_TEST(adres.get_streetName()=="Pilsudskiego");
//        BOOST_TEST_WARN(adres.get_streetName()=="");
//        adres.set_streetNumber("");
//        BOOST_TEST(adres.get_streetNumber()=="36");
//        BOOST_TEST_WARN(adres.get_streetNumber()=="");
//    }

BOOST_AUTO_TEST_SUITE_END()
