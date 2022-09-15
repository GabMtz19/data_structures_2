//Inlcusion de las librerias y estructuras necesarias
#include "Date.h"
#include "Time.h"
#include <iostream>
using namespace std;

//Cuerpo de la estructura
struct Entries
{   
    //Atributos
    int overall_time;
    string ip_address,login_fail;
    Date date_m_d;
    Time time_h_m_s;

    //Metodos constructores
    Entries();
    Entries(string,string,string,int,int,int,int,int);

    //Metodo de la clase
    void display();
};

//Constructor sin parametros
Entries::Entries() {
    ip_address = "-";
    login_fail = "-";
}

//Constructor con parametros
Entries::Entries(string ip_address,string login_fail,string month,int day,int hour,int minute,int second,int overall_time) {
    this->ip_address = ip_address;
    this->login_fail = login_fail;
    date_m_d.month = month;
    date_m_d.day = day;
    time_h_m_s.hour = hour;
    time_h_m_s.minute = minute;
    time_h_m_s.second = second;
    this->overall_time = overall_time;
}

//Metodo que despliega los datos de un objeto
void Entries::display() {
    date_m_d.display();
    time_h_m_s.display();
    cout << ip_address << login_fail << endl;
}