//Inclusion de las clases y librerias necesarias
#include "GraphP.h"
#include <fstream>
#include <chrono>
using namespace std;

//Funcion encargada de leer los datos del archivo 
//y crear el grafo a partir de estos datos 
//O(n)
template<class T>
void readFile(GraphP<T>& graph) {

    //Se inicializan el archivo y las variables
    //para almacenar la informacion necesarias
    ifstream myFile;
    myFile.open("Entrega 4/bitacoraACT4_3.txt");
    int numVertex,numEdge;
    myFile >> numVertex >> numEdge;
    string iP;

    //Se obtienen todos los vertices existentes
    for(int c = 0;c < numVertex;c++) {
        myFile >> iP;
        IP<T> iPValue(iP);
        graph.addVertex(iPValue);
    }

    //Se obtienen todas las adyacencias que se encuentran en el archivo
    string month,day,time,origin,destination,fail;
    for(int c = 0;c < numEdge;c++) {
        myFile >> month >> day >> time >> origin >> destination;
        getline(myFile,fail);
        string dateTime = month + " " + day + " " + time;
        int position = origin.find(':');
        string portO = origin.substr(position,-1);
        origin.erase(position,-1);
        position = destination.find(':');
        string portD = destination.substr(position,-1);
        destination.erase(position,-1);
        vector<string> ports = {portO,portD};
        Login edgeInfo(dateTime,fail,ports);
        IP<T> originIP(origin);
        IP<T> destinationIP(destination);
        graph.addEdge(originIP,destinationIP,edgeInfo);
    }

    //Se regresa a la funcion principal del programa
    return;

}


//Funcion principal
//O(n)
int main() {

    //Se incia a contar el tiempo de ejecucion del programa
    auto start = chrono::high_resolution_clock::now();

    //Se crea el grafo y se obtienen los datos necesarios
    GraphP<string> graph;
    readFile(graph);

    //Se imprime el grafo ya una vez creado
    graph.print();

    //Se realiza el metodo max heap para obtener la IP
    //que cuente con un mayor numero de adyacencias
    vector<EdgeP<string>> adjList;
    adjList = graph.getAdjList();
    DLL<string> dLinkedList;
    for(auto edge : adjList) {
        dLinkedList.addFirst(edge);
    }
    heapP<string> heapTree(dLinkedList);
    EdgeP<string> maxEdges = heapTree.remove();
    cout << "The IP with the most edges being origin is: \n";
    maxEdges.print();

    //Se termina de contar el tiempo de ejecucion
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << "Program execution time: " << time.count() << endl;

    //Se termina el programa
    system("pause");
    return 0;

}