//Inclusion de las librerias y clases necesarias
#include "heap_Tree.h"
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

//Se realiza el metodo heap_sort
template<class T>
void heapSort(DoublyLinkedList<T>& listDLL) {
    //Se crea un arbol_heap para almacenar los datos de la DLL
    heap<T> heap_tree(listDLL);

    //Se borran los elementos de la DLL para
    //volver a ingresarlos de forma ordenada
    listDLL.clear();

    //Se ingresan los valores en el orden determinado haciendo uso
    //del remove, siendo que nos regresa el elemento
    while(!heap_tree.isEmpty()) {
        listDLL.addFirst(heap_tree.remove());
    }
}

//Se obtienen los registros del archivo bitacora2.txt
template<class T>
void obtainData(DoublyLinkedList<T>& listDLL) {
    //Se inicializan las variables necesarias
    //para el procesamiento del archivo
    ifstream myFile;
    string month,day,time,ipPort,failedLogin,dateTime,IP,ip;
    int ipValue;
    
    //Se abre el archivo
    myFile.open("Entrega 3/bitacora2.txt");

    //Se leen los datos del archivo hasta llegar al final del mismo
    while(! myFile.eof()) {
        
        //Se obtienen los datos principales
        myFile >> month >> day >> time >> ipPort;
        getline(myFile,failedLogin);

        //Se obtiene la ip como valor numerico para las agrupaciones
        ip = "";
        dateTime = month + " " + day + " " + time;
        IP = ipPort.substr(0,ipPort.find(':'));
        while(IP.find('.') != -1) {
            int position = IP.find('.');
            ip += IP.substr(0,position);
            IP.erase(0,position + 1);
        }
        ip += IP;
        ipValue = atoi(ip.c_str());

        //Se crea un objeto con los datos del registro
        //registro y se ingresa en la DLL
        logins element(dateTime,ipPort,failedLogin,ipValue,1);
        listDLL.addFirst(element);
    }
}

//Se obtienen las ips y el numero de registros
template<class T>
void assignUniqueIps(heap<T>& uniqueIps,DoublyLinkedList<T> listDLL) {
    //Se obtienen las IPs unicas y sus registros
    Queue<T> queue = listDLL.getQueue();

    //Mientras queden valores en el queue,
    //se ingresan al heap de IPs unicas
    while(!queue.isEmpty()) {
        T element = queue.dequeue();
        element.setComparison(2);
        uniqueIps.insert(element);
    }
}

//Funcion principal
int main() {
    //Se comienza a tomar el tiempo de ejecucion
    auto start = chrono::high_resolution_clock::now();

    //Se almacenan los registros dentro de una DLL
    DoublyLinkedList<logins> listDLL;
    obtainData(listDLL);

    //Se ordenan los registros a traves del metodo Heap_Sort
    heapSort(listDLL);

    //Se obtienen las IPs unicas y su numero de registros
    heap<logins> uniqueIps;
    assignUniqueIps(uniqueIps,listDLL);

    //Imprimimos las 5 IPs con mas registros
    for(int c = 1;c <= 5;c++) {
        cout << c << ".- ";
        uniqueIps.remove().printRep();
    }
    cout << endl;

    //Se termina de contar el tiempo de ejecucion y se imprime
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << time.count() << endl;
    return 0;
}