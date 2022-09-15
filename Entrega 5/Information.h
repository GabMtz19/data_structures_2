#include <iostream>
#include <vector>
using namespace std;

struct Information {

    string dateTime,failureType;
    vector<string> ports;

    Information(string,string,string,string);
    void print();

};  

Information::Information(string dateTime,string failureType,string port1,string port2) {
    this->dateTime = dateTime;
    this->failureType = failureType;
    ports.push_back(port1);
    ports.push_back(port2);
}

void Information::print() {
    cout << "Date & Time: " << dateTime << endl <<
    "Origin Port: " << ports[0] << endl <<
    "Destination Port: " << ports[1] << endl <<
    "Failure Type: " << failureType << endl << endl;
}