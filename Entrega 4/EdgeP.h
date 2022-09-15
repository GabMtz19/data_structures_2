#include "IP.h"
#include "Login.h"
#include <vector>
using namespace std;

template<class T>
struct EdgeP {
    IP<T> origin;
    vector<IP<T>> destinations;
    vector<Login> info;
    int numEdges;
    EdgeP();
    EdgeP(IP<T>);
    EdgeP(IP<T>,vector<IP<T>>,vector<Login>);
    void addDestination(IP<T>,Login);
    void print();
    bool operator>(EdgeP<T>);
    bool operator<=(EdgeP<T>);
    bool operator<(EdgeP<T>);
};

template<class T>
EdgeP<T>::EdgeP() {
    numEdges = 0;
}

template<class T>
EdgeP<T>::EdgeP(IP<T> origin) {
    this->origin = origin;
    numEdges = 0;
}

template<class T>
EdgeP<T>::EdgeP(IP<T> origin,vector<IP<T>> destinations,vector<Login> info) {
    this->origin = origin;
    this->destinations = destinations;
    this->info = info;
    numEdges = 1;
}

template<class T>
void EdgeP<T>::addDestination(IP<T> destination,Login edgeInfo) {
    destinations.push_back(destination);
    info.push_back(edgeInfo);
    numEdges++;
}

template<class T>
void EdgeP<T>::print() {
    cout << "IP: " << origin.data << endl <<
    "Edges: " << numEdges << endl;
    cout.fill('-');
    cout.width(30);
    cout << "\n";
    for(int c = 0;c < numEdges;c++) {
        cout << "Origin: " << origin.data << " / Destination: " << destinations[c].data << endl;
        info[c].print();
        cout << endl;
    }
    cout << endl;
}

template<class T>
bool EdgeP<T>::operator>(EdgeP<T> comparison) {
    return numEdges > comparison.numEdges;
}

template<class T>
bool EdgeP<T>::operator<=(EdgeP<T> comparison) {
    return numEdges <= comparison.numEdges;
}

template<class T>
bool EdgeP<T>::operator<(EdgeP<T> comparison) {
    return numEdges < comparison.numEdges;
}
