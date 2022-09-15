//Inclusion de las librerias
#include <iostream>
using namespace std;

//Cuerpo de la estructura
struct Date
{
    //Atributos
    string month;
    int day;

    //Metodos constructores
    Date();
    Date(string,int);

    //Metodo de la clase
    void display();
};

//Constructor sin parametros
Date::Date() {
    month = "-";
    day = 0;
}

//Constructor con parametros
Date::Date(string month,int day) {
    this->month = month;
    this->day = day;
}

/*Metodo que despliega los
datos de la estuctura*/
void Date::display() {
    cout << month << " " << day << " ";
}