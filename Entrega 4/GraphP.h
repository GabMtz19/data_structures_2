//Inclusion de las librerias y clases necesarias
#include "heapP.h"
using namespace std;

//Se crea la clase GraphP utilizando templates
template<class T>
class GraphP {

    //Atributos y metodos privados de la clase
    private:
        
        //Atributos basicos de una lista de adyacencias
        vector<EdgeP<T>> adjList;
        vector<IP<T>> vertices;
        int numVertices,numEdges;

        //Metodo privado de la clase
        int findVertex(IP<T>); 

    //Metodos publicos de la clase
    public:

        //Metodo constructor por default
        GraphP();

        //Metodos privados de la clase
        void addVertex(IP<T>);
        void addEdge(IP<T>,IP<T>,Login);
        void print();
        vector<EdgeP<T>> getAdjList();

};

//Metodo que encuentra la ubicacion de un vertice en caso de existir
template<class T>
int GraphP<T>::findVertex(IP<T> vertex) {

    //Se recorre todo el vector de vertices
    //en busca del elemento solicitado
    for(int c = 0;c < numVertices;c++) {
        if(vertices[c] == vertex) { //En caso de encontrarse se regresa
            return c;               //la posicion
        }
    }
    return -1;  //Del caso contrario, se regresa un valor de -1

}

//Metodo constructor por default
template<class T>
GraphP<T>::GraphP() {

    //Se establecen los valores iniciales como 0
    numVertices = 0;
    numEdges = 0;

}

//Metodo para agregar un vertice al vector de vertices
template<class T>
void GraphP<T>::addVertex(IP<T> vertex) {

    //Se busca si el vertice no existia ya
    int position = findVertex(vertex);
    if(position < 0) {  //En caso de no existir, se agrega al vector
        vertices.push_back(vertex); //y en caso de si existir, simplemente
        EdgeP<T> newEdge(vertex);   //no se agrega
        adjList.push_back(newEdge);
        numVertices++;
    }

}

//Metodo para agregar una adyacencia
template<class T>
void GraphP<T>::addEdge(IP<T> origin,IP<T> destination,Login edgeInfo) {

    //Se busca si el elemento origen no existia ya en el vector de vertices
    int positionO = findVertex(origin);
    if(positionO >= 0) {    //En caso de si existir, se agrega el destino en la posicion
        adjList[positionO].addDestination(destination,edgeInfo);    //del origen
        numEdges++;
    }
    else {  //En caso de no existir
        vertices.push_back(origin); //Se agrega en la lista de vertices
        vector<IP<T>> destinations = {destination};
        vector<Login> info = {edgeInfo};
        EdgeP<T> newEdge(origin,destinations,info); //Se agrega una nueva adyacencia del origen
        adjList.push_back(newEdge); //con el destino, ademas de la informacion del arco
        numVertices++;  //Se incrementa el numero de vertices y adyacencias
        numEdges++;
    }

    //Se busca si el destino no estaba contemplado en el vector de vertices
    int positionD = findVertex(destination);
    if(positionD < 0) { //En caso de no estar contemplado, se agrega pero no se
        vertices.push_back(destination);    //contempla en la imprecion del grafo
        numVertices++;
    }

}

//Metodo que imprime los datos de las adyacencias
template<class T>
void GraphP<T>::print() {

    //Se recorren todas las adyacencias existentes
    for(auto edge : adjList) {
        edge.print();   //Se manda a llamar el metodo print de las adyacencias
        cout << endl;
    }
    cout << endl;

}

//Metodo get que regresa la lista de adyacencias
template<class T>
vector<EdgeP<T>> GraphP<T>::getAdjList() {

    //Se hace return a la lista de adyacencias "adjList"
    return adjList;

}