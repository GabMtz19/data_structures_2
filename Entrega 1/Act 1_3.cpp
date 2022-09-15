/*Gabriel Martinez Berrones
A00517149
Actividad 1.3.0*/

//Inclusion de las librerias y estructuras necesarias
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <chrono>
#include "Entries.h"
using namespace std;

//Se obtiene un valor numerico de la fecha
//O(n)
int obtainTime(string month,int day,int hour,int minute,int second) {
    //Inicializacion de variables
    int overall_time,int_month;
    string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

    //Se obtiene cual es el numero del mes
    //y se le asigna un valor determinado
    for(int m = 1;m < 13;m++) {
        if(month == months[m - 1]) {
            int_month = 3000000 * m;
        }
    }
    day *= 86400;
    hour *= 3600;
    minute *= 60;

    return int_month + day + hour + minute + second;
}

//Se lee el archivo para obtener todas las entradas de la bitacora
//O(1)
void read(vector<Entries> &list_entries) {
    //Inicializacion de las variables
    ifstream file;
    string month,time,ip_address,login_fail,line;
    int day;
    file.open("Entrega 1/bitacora.txt");

    //Mientras no se termine el archivo, se sigue obteniendo informacion
    while(! file.eof()) {
        file >> month >> day >> time >> ip_address;

        //Se obtienen los valores de tiempo por separado
        int position = time.find(':');
        int hour = atoi(time.substr(0,position).c_str());
        time.erase(0,position + 1);
        position = time.find(':');
        int minute = atoi(time.substr(0,position).c_str());
        time.erase(0,position + 1);
        int second = atoi(time.c_str());

        getline(file,line);
        login_fail = line;

        //Se obtiene el valor numerico de la fecha
        int overall_time = obtainTime(month,day,hour,minute,second);

        //Se crea un objeto con los valores de la entrada y se asigna al vector
        Entries entry(ip_address,login_fail,month,day,hour,minute,second,overall_time);
        list_entries.push_back(entry);
    }
}


//Algoritmo de ordenamiento para ordenar por fecha
//O(n^2)
void merge(vector<Entries> &list_entries,int low,int mid,int high) {
    //Inicializacion de las variables
    int left_part = mid - low + 1;
    int right_part = high - mid;
    vector<Entries> left_elements;
    vector<Entries> right_elements;

    //Se asignan los valores de la parte izquierda
    //y derecha a su respectivo vector
    for(int e = 0;e < left_part;e++) {
        left_elements.push_back(list_entries[low + e]);
    }
    for(int e = 0;e < right_part;e++) {
        right_elements.push_back(list_entries[mid + 1 + e]);
    }

    //Contadores para cada vector
    int left = 0;
    int right = 0;
    int general = low;

    //Se comienzan a ordenar los elementos
    while(left < left_part && right < right_part) {
        if(left_elements[left].overall_time <= right_elements[right].overall_time) {
            list_entries[general] = left_elements[left];
            general++;
            left++;
        }
        else {
            list_entries[general] = right_elements[right];
            general++;
            right++;
        }
    }

    //En caso de sobrar elementos en los vectores se asignan al vector original
    while(left < left_part) {
        list_entries[general] = left_elements[left];
        general++;
        left++;
    }   
    while(right < right_part) {
        list_entries[general] = right_elements[right];
        general++;
        right++;
    }
}


//Funcion de separamiento para el metodo Merge Sort
//O(2^n)
void mergeSort(vector<Entries> &list_entries,int low,int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(list_entries,low,mid);
        mergeSort(list_entries,mid + 1,high);
        merge(list_entries,low,mid,high);
    }
}

/*Busqueda binaria para encontrar las 
entradas solicitadas por el usuario*/
//O(n)
int binarySearch(vector<Entries> list_entries,int length,int date) {
    //Inicializacion de las variables
    int inf = 0;
    int sup = length;
    int mid = length / 2;

    //Comienza el algoritmo de busqueda binaria
    while(list_entries[mid].overall_time != date && inf != sup) {
        if(date > list_entries[mid].overall_time) {
            inf = mid + 1;
            mid = inf + ((sup - inf) / 2);
        }
        else {
            sup = mid - 1;
            mid = inf + ((sup - inf) / 2);
        }
    }

    //En caso de existir la entrada solicitada,
    //se regresa su posicion
    if(date == list_entries[mid].overall_time) {
        return mid;
    }

    /*En caso de no existir, se regresa la posicion del
    elemento mas cercano a la fecha solicitada*/
    else {
        /*Se obtienen las diferencias entre el valor solicitado y 
        el valor del medio, medio + 1 y medio - 1*/
        int m = abs(list_entries[mid].overall_time - date);
        int m_m_1 = abs(date - list_entries[mid - 1].overall_time);
        int m_p_1 = abs(list_entries[mid + 1].overall_time - date);

        //Se centran en un arreglo y se obtiene cual diferencia es menor
        int values[] = {m,m_m_1,m_p_1};
        int min_pos = 0,min = values[min_pos];    // Mar 15     Mar 20     Mar 25
        for(int c = 1;c < 3;c++) {
            if(values[c] < min) {
                min = values[c];
                min_pos = c;
            }
        }

        //Se regresa la posicion del valor mas cercano al solicitado
        if(min_pos == 0) {
            return mid;
        }
        else if(min_pos == 1) {
            return mid - 1;
        }
        else {
            return mid + 1;
        }
    } 
}

//Creacion del nuevo archivo con los datos dentro del rango establecido
//O(n)
void createFile(vector<Entries> list_entries,int length,int in_pos,int end_pos) {
    //Se crea la variable del archivo
    ofstream new_file("Entrega 1/entries.txt");

    //Se comienzan a agregar todas las entradas dentro del archvivo
    for(int c = in_pos;c <= end_pos;c++) {
        //Se crean nueva variables con los datos concatenados
        string date = list_entries[c].date_m_d.month + " " + to_string(list_entries[c].date_m_d.day) + " ";
        string time = to_string(list_entries[c].time_h_m_s.hour) + ":" + to_string(list_entries[c].time_h_m_s.minute) + 
        ":" + to_string(list_entries[c].time_h_m_s.second) + " ";

        /*Se despliegan los datos para que el usuario pueda 
        visualizarlos conforme se agregan al archivo*/
        list_entries[c].display();

        //Se insertan los datos dentro del archivo
        new_file << date << time << list_entries[c].ip_address << list_entries[c].login_fail;
        if(c != end_pos) {
            new_file << endl;
        }
    }
}

/*Se solicitan los parametros de busqueda para generar el nuevo archivo
y se mandan a llamar el resto de funciones*/
//O(n^2)
void search(vector<Entries> list_entries,int length) {
    //Inicializacion de las variables
    int day,hour,minute,second,initial_date,end_date,in_date_pos,end_date_pos;
    string month;
    string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

    /*Se obtienen las posiciones de la fecha
    inicial y la final para la busqueda*/
    for(int c = 0;c < 2;c++) {
        if(c == 0) {
            cout << "Enter the necessary data for your initial date: \n";
        }
        else {
            cout << "Enter the necessary data for your end date: \n";
        }

        //Se piden los valores necesarios para comenzar la busqueda
        for(int c = 0;c < 12;c++) {
            cout << "[" << months[c] << "] ";
        }
        cout << endl;
        cout << "Month (first three letters of the month): ";
        cin >> month;
        cout << "Day: ";
        cin >> day;
        cout << "Hour: ";
        cin >> hour;
        cout << "Minute: ";
        cin >> minute;
        cout << "Second: ";
        cin >> second;

        //Se obtienen la posicion de la fecha final y la fecha incial
        if(c == 0) {
            initial_date = obtainTime(month,day,hour,minute,second);
            in_date_pos = binarySearch(list_entries,length,initial_date);
        }
        else {
            end_date = obtainTime(month,day,hour,minute,second);
            end_date_pos = binarySearch(list_entries,length,end_date);
        }
    }

    //Se manda a llamar la funcion para crear el archivo
    createFile(list_entries,length,in_date_pos,end_date_pos);
}


//Funcion principal del programa
//O(1)
int main() {
    //Inicia a contar el tiempo de ejecucion
    auto start = chrono::high_resolution_clock::now();

    //Inicializacion del vector
    vector<Entries> list_entries;
    read(list_entries);
    int length = list_entries.size();

    //Se ordenan los elementos del vector
    mergeSort(list_entries,0,length - 1);

    //Se buscan los datos necesarios y se crea el archivo
    search(list_entries,length);

    cout << "\nThe requested data has now been stored in \"entries.txt\" \n";

    /*Se termina de contar el tiempo
    de ejecucion y se despliega*/
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << "Program execution time: " << time.count() << endl;

    return 0;
}     