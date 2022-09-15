#include <iostream>
using namespace std;

class logins {
    private:
        string dateTime,ipPort,failedLogin;
        int ip,ipRep,comparison;
    public:
        logins();
        logins(string,string,string,int,int);
        void setComparison(int);
        int getIp();
        void addRep();
        void print();
        bool operator>(logins);
        bool operator==(logins);
        void printRep();
};

logins::logins() {
    dateTime = "- - -:-:-";
    ipPort = "-.-.-.-:-";
    failedLogin = "- - -";
    ip = 0;
    ipRep = 1;
    comparison = 0;
}

logins::logins(string dateTime,string ipPort,string failedLogin,int ip,int comparison) {
    this->dateTime = dateTime;
    this->ipPort = ipPort;
    this->failedLogin = failedLogin;
    this->ip = ip;
    this->comparison = comparison;
    ipRep = 1;
}

void logins::setComparison(int compValue) {
    comparison = compValue;
}

int logins::getIp() {
    return ip;
}

void logins::addRep() {
    ipRep += 1;
}

void logins::print() {
    cout << dateTime << " " << ipPort << failedLogin << " Comparison Ip: " << ip << " Repetitions: " << ipRep << endl;
}

void logins::printRep() {
    string ipStr = ipPort.substr(0,ipPort.find(':'));
    cout << "IP: " << ipStr << " / Repetitions: " << ipRep << endl;
}

bool logins::operator>(logins elementComp) {
    if(comparison == 1) {
        return ip > elementComp.ip ? true : false;
    }
    else if(comparison == 2) {
        return ipRep > elementComp.ipRep ? true : false;
    }
}

bool logins::operator==(logins elementComp) {
    if(comparison == 1) {
        return ip == elementComp.ip ? true : false;
    }   
    else if(comparison == 2) {
        return ipRep == elementComp.ipRep ? true : false;
    }
}