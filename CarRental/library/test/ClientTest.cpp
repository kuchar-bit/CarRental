#include <boost/test/unit_test.hpp>

using namespace std;

#include "model/Client.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jerzy";
    const std::string testLastName = "Polomowicz";
    const std::string testPersonalID = "0123456789";
    const std::string noweImie = "Jakub";
    Address *testaddress1;
    Address *testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = new Address("Rzgów", "Jemiołowa", "37");
        testaddress2 = new Address("Rogów", "Wierzbowa", "23");
    }

    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTest)
    {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST_CHECK(klient.get_firstName()==testFirstName);
        BOOST_TEST_CHECK(klient.get_lastName()==testLastName);
        BOOST_TEST_CHECK(klient.get_personalID()==testPersonalID);
        BOOST_TEST_CHECK(klient.get_adres()==testaddress1);
        BOOST_TEST_CHECK(klient.getCurrentRents().empty());
    }

    BOOST_AUTO_TEST_CASE(SetFirstNamePositiveTest)
    {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.set_firstName(noweImie);
        BOOST_TEST_CHECK(klient.get_firstName()=="Jakub");
    }

    BOOST_AUTO_TEST_CASE(SetFirstNameNegativeTest)
    {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.set_firstName("");
        BOOST_TEST_CHECK(klient.get_firstName()=="Michal");
    }

    BOOST_AUTO_TEST_CASE(SetLastNamePositiveTest)
    {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.set_lastName("Jeziorski");
        BOOST_TEST_CHECK(klient.get_lastName()=="Jeziorski");

    }

    BOOST_AUTO_TEST_CASE(SetLastNameNegativeTest)
    {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.set_lastName("");
        BOOST_TEST_CHECK(klient.get_lastName()==testLastName);
    }

    BOOST_AUTO_TEST_CASE(SetAddressPositiveTest)
    {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.set_adres(testaddress2);
        BOOST_TEST_CHECK(klient.get_adres()==testaddress2);
    }

    BOOST_AUTO_TEST_CASE(SetAddressNegativeTest)
    {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.set_adres(nullptr);
        BOOST_TEST_CHECK(klient.get_adres()==testaddress1);
    }

BOOST_AUTO_TEST_SUITE_END()
