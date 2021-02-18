#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Vehicle.h"

struct TestSuiteRentFixture{
    const std::string testFirstName = "Maciej";
    const std::string testLastName = "Figurowski";
    const std::string testPersonalID = "0987654321";
    const std::string testPlateNumber="6996";
    const unsigned int testBasePrice=30;
    pt::ptime testBeginTime=pt::ptime(gr::date(2020,4,18),pt::hours(9)+pt::minutes(25));
    pt::ptime testEndTime=pt::ptime(gr::date(2020,4,22),pt::hours(9)+pt::minutes(25));
    pt::ptime testDefaultTime=pt::not_a_date_time;
    pt::ptime testCurrentTime=pt::second_clock::local_time();
    const unsigned int testID=10;
    Client *testClient;
    Vehicle *testVehicle;
    Address *testaddress;

    TestSuiteRentFixture() {
        testaddress = new Address("Lodz", "Pilsudskiego", "36");
        testClient=new Client(testFirstName,testLastName,testPersonalID,testaddress);
        testVehicle=new Vehicle(testPlateNumber,testBasePrice);
    }

    ~TestSuiteRentFixture() {
        delete testaddress;
        delete testClient;
        delete testVehicle;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)
    BOOST_AUTO_TEST_CASE(RentConstructorTestGivenBeginTime)
    {
        Rent* r=new Rent(testID, testVehicle, testClient, testBeginTime);
        BOOST_TEST_REQUIRE(r->get_client()==testClient);
        BOOST_TEST_CHECK(r==testClient->getCurrentRents()[0]);
        BOOST_TEST_CHECK(r->get_ID()==testID);
        BOOST_TEST_REQUIRE(r->get_vehicle()==testVehicle);
        BOOST_TEST_CHECK(testVehicle->isRented());
        BOOST_TEST_CHECK(r->get_beginTime()==testBeginTime);
        BOOST_TEST_CHECK(r->get_endTime()==pt::not_a_date_time);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentConstructorTestGivenDefaultTime)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testDefaultTime);
        BOOST_TEST_REQUIRE(!r->get_beginTime().is_not_a_date_time());
        pt::time_period skew = pt::time_period(r->get_beginTime(), testCurrentTime);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentBasicTest)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(!r->get_vehicle()->isRented());
        BOOST_TEST_CHECK(&r!=&testClient->getCurrentRents()[0]);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        r->endRent(testDefaultTime);
        Rent *r2 = new Rent(testID, testVehicle, testClient, testBeginTime);
        r2->endRent(testCurrentTime);
        BOOST_TEST_CHECK(r->get_endTime()==testCurrentTime);
        BOOST_TEST_CHECK(r2->get_endTime()==testCurrentTime);

        delete r;
        delete r2;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(r->get_endTime()==testEndTime);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->get_endTime()==testBeginTime);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testEndTime);
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->get_endTime()==testEndTime);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        BOOST_TEST_CHECK(r->getRentDays()==0);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        pt::ptime preminute=pt::ptime(gr::date(2020,4,17),pt::hours(9)+pt::minutes(25)+pt::seconds(40));
        r->endRent(preminute);
        BOOST_TEST_CHECK(r->getRentDays()==0);
        delete r;
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        pt::ptime minute=pt::ptime(gr::date(2020,4,17),pt::hours(9)+pt::minutes(26));
        r->endRent(minute);
        BOOST_TEST_CHECK(r->getRentDays()==1);
        delete r;
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        pt::ptime notquiteaday=pt::ptime(gr::date(2020,4,18),pt::hours(9)+pt::minutes(24));
        r->endRent(notquiteaday);
        BOOST_TEST_CHECK(r->getRentDays()==1);
        delete r;
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        pt::ptime aday=pt::ptime(gr::date(2020,4,18),pt::hours(9)+pt::minutes(25));
        r->endRent(aday);
        BOOST_TEST_CHECK(r->getRentDays()==2);
        delete r;
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        r->endRent(testEndTime);
        int temp=r->getRentDays();
        r->endRent(testDefaultTime);
        BOOST_TEST_CHECK(r->getRentDays()==temp);
        delete r;
    }
    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIs0)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->get_rentCost()==0);
        delete r;
    }
    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIsPositive)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(r->get_rentCost()==90);
        delete r;
    }
    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged)
    {
        Rent *r = new Rent(testID, testVehicle, testClient, testBeginTime);
        r->endRent(testEndTime);
        testVehicle->set_basePrice(100);
        BOOST_TEST_CHECK(r->get_rentCost()==90);
        delete r;
    }
BOOST_AUTO_TEST_SUITE_END()