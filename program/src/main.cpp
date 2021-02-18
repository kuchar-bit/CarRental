// Header file for input output functions

#include<iostream>
#include <model/Client.h>

using namespace std; 

int main() 
{
    cout<<"Witam w wypożyczalni samochodów"<<endl;

    Client local("Jan","Kowalski","02436456942");
    Client *dynamic = new Client("Stanisław","Chada","45286719578");

    cout<<"Klient numer 1" << endl;
    cout<<local.getClientInfo() << endl;

    cout<<"Klient numer 2" << endl;
    cout<<dynamic->getClientInfo()<< endl;

    local.set_personalid("");
    cout << local.getClientInfo();

    delete dynamic;

    return 0;
} 

