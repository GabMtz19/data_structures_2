#include <iostream>
#include <vector>
using namespace std;

struct Login {
    string dateTime,fail;
    vector<string> ports;
    Login();
    Login(string,string,vector<string>);
    void print();
};

Login::Login() {
    dateTime = "-";
    fail = "-";
}

Login::Login(string dateTime,string fail,vector<string> ports) {
    this->dateTime = dateTime;
    this->fail = fail;
    this->ports = ports;
}

void Login::print() {
    cout << "Date & Time: " << dateTime << endl <<
    "Fail motive: " << fail << endl <<
    "Ports: " << ports[0] << " & " << ports[1] << endl;
}