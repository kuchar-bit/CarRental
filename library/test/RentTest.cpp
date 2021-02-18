#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Vehicle.h"
#include "model/Car.h"
#include "model/Moped.h"
#include "model/Bicycle.h"

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
    ClientPtr testClient;
    VehiclePtr testCar;
    AddressPtr testAddress;

    TestSuiteRentFixture()
    {
        testAddress = std::make_shared<Address>("Lodz", "Pilsudskiego", "36");
        testClient = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress);
        testCar = std::make_shared<Car>(testPlateNumber, testBasePrice, 1000, Car::B);
    }

    ~TestSuiteRentFixture()
    {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(RentConstructorTestGivenBeginTime)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        BOOST_TEST_REQUIRE(r->get_client() == testClient);
        BOOST_TEST_CHECK(r->get_ID()==testID);
        BOOST_TEST_REQUIRE(r->get_vehicle()==testCar);
        BOOST_TEST_CHECK(r->get_beginTime()==testBeginTime);
        BOOST_TEST_CHECK(r->get_endTime()==pt::not_a_date_time);
    }

    BOOST_AUTO_TEST_CASE(RentConstructorTestGivenDefaultTime)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        BOOST_TEST_REQUIRE(!r->get_beginTime().is_not_a_date_time());
        pt::time_period okres = pt::time_period(r->get_beginTime(), testCurrentTime);
        BOOST_TEST((okres.length().hours()==0 && okres.length().minutes()==0));
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        r->endRent(testDefaultTime);
        RentPtr r2(new Rent(testID, testCar, testClient, testBeginTime));
        r2->endRent(testCurrentTime);
        BOOST_TEST_CHECK(r->get_endTime()==testCurrentTime);
        BOOST_TEST_CHECK(r2->get_endTime()==testCurrentTime);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(r->get_endTime()==testEndTime);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->get_endTime()==testBeginTime);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->get_endTime()==testEndTime);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        BOOST_TEST_CHECK(r->getRentDays()==0);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        pt::ptime preminute=pt::ptime(gr::date(2020,4,17),pt::hours(9)+pt::minutes(25)+pt::seconds(40));
        r->endRent(preminute);
        BOOST_TEST_CHECK(r->getRentDays()==0);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        pt::ptime minute=pt::ptime(gr::date(2020,4,17),pt::hours(9)+pt::minutes(26));
        r->endRent(minute);
        BOOST_TEST_CHECK(r->getRentDays()==1);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        pt::ptime notquiteaday=pt::ptime(gr::date(2020,4,18),pt::hours(9)+pt::minutes(24));
        r->endRent(notquiteaday);
        BOOST_TEST_CHECK(r->getRentDays()==1);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        pt::ptime aday=pt::ptime(gr::date(2020,4,18),pt::hours(9)+pt::minutes(25));
        r->endRent(aday);
        BOOST_TEST_CHECK(r->getRentDays()==2);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        r->endRent(testEndTime);
        int temp=r->getRentDays();
        r->endRent(testDefaultTime);
        BOOST_TEST_CHECK(r->getRentDays()==temp);
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIs0)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->get_rentCost()==0);
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIsPositive)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(r->get_rentCost()==90);
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged)
    {
        RentPtr r(new Rent(testID, testCar, testClient, testBeginTime));
        r->endRent(testEndTime);
        testCar->set_basePrice(100);
        BOOST_TEST_CHECK(r->get_rentCost()==90);
    }

BOOST_AUTO_TEST_SUITE_END()