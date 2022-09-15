#include <iostream>
using namespace std;

struct Atributes {
    string month,ipAdress,failLogin;
    int day,hour,minute,second,overallTime;
    Atributes();
    Atributes(string,string,string,int,int,int,int,int);
    void print();
};

Atributes::Atributes() {
    month = " ";
    ipAdress = " ";
    failLogin = " ";
    day = 0;
    hour = 0;
    minute = 0;
    second = 0;
    overallTime = 0;
}

Atributes::Atributes(string month,string ipAdress,string failLogin,int day,int hour,int minute,int second,int overallTime) {
    this->month = month;
    this->ipAdress = ipAdress;
    this->failLogin = failLogin;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->overallTime = overallTime;
}

void Atributes::print() {
    cout << month << " " << day << " " << hour << ":" << minute << ":" << second << " " << ipAdress << failLogin << " " << overallTime << endl;
}