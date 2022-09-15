#include <iostream>
#include <fstream>
#include "DoublyLL.h"
using namespace std;

int obtainTime(string month,int day,int hour,int minute,int second) {
    int monthInt;
    string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for(int c = 0;c < 12;c++) {
        if(month == months[c]) {
            monthInt = (c + 1) * 2678400; 
        }
    }
    day *= 86400;
    hour *= 3600;
    minute *= 60;
    return monthInt + day + hour + minute + second;
}

void createDLL(DoublyLL& DLL) {
    ifstream myfile;
    string month,time,ipAddress,failLogin;
    int day;
    myfile.open("Entrega 2/bitacora.txt");
    while(! myfile.eof()) {
        myfile >> month >> day >> time >> ipAddress; 
        int position = time.find(':');
        int hour = atoi(time.substr(0,position).c_str());
        time.erase(0,position + 1);
        position = time.find(':');
        int minute = atoi(time.substr(0,position).c_str());
        time.erase(0,position + 1);
        int second = atoi(time.c_str());
        getline(myfile,failLogin);
        int overallTime = obtainTime(month,day,hour,minute,second);
        Atributes data(month,ipAddress,failLogin,day,hour,minute,second,overallTime);
        DLL.add(data);
    }
}

int main() {
    DoublyLL DLL;
    createDLL(DLL);
    DLL.mergeSort(0,DLL.size - 1);
    DLL.print();
    return 0;
}