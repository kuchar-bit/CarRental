#include <iostream>
#include "model/Client.h"
#include <boost/date_time.hpp>
#include "model/Rent.h"
using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

int main()
{
    Address address("New York","7th","23");
    string fname1 = "Janek";
    Client klient(fname1, "Arbuckle", "0123456789",&address);
    fname1.assign("Patryk");
    cout << klient.get_firstName() << endl;

    string fname2 = "Elisa";
    klient.set_firstName(fname2);
    fname2.assign("Jacob");
    cout << klient.get_firstName() << endl;
    Vehicle* mercedes=new Vehicle("LDZ23",12);
    cout << mercedes->getVehicleInfo()<<endl;
    //cout << c.getCurrentRents()<<endl;
    pt::ptime empty = pt::not_a_date_time;
    cout << empty << endl;
    pt::ptime now = pt::second_clock::local_time();
    cout << empty.is_not_a_date_time();
    cout << now << endl;
    pt::ptime then = pt::ptime(gr::date(2020,4,17),pt::hours(9)+pt::minutes(25));
    pt::ptime then2 = pt::ptime(gr::date(2020,4,17),pt::hours(12)+pt::minutes(25));
    cout << then << endl;
    pt::time_period period(then, then2);
    cout << period << endl;
    cout << period.length() << endl;
    cout << period.length().hours() << endl;
    cout << period.length().minutes() << endl;
    //cout << (then>now) << endl;
    //cout << (then<=now) << endl;
    Rent wypozyczenie(1, mercedes, &klient, then);
    wypozyczenie.endRent(now);
    //cout << wypozyczonko.getRentDays()<<endl;
    //cout << c.getFullClientInfo();


    return 0;

}
