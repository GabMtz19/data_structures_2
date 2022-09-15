//Inclusion de las librerias
#include <iostream>
using namespace std;

//Cuerpo de la estructura
struct Time
{
    //Atributos
    int hour,minute,second;

    //Metodos constructores
    Time();
    Time(int,int,int);

    //Metodo de la clase
    void display();
};

//Constructor sin parametors
Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

//Constructor con parametros
Time::Time(int hour,int minute,int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;  
}

//Metodo que despliega los datos de la estructura
void Time::display() {
    cout << hour << ":" << minute << ":" << second << " ";
}