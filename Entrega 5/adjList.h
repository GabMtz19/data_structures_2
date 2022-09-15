#include "Information.h"
using namespace std;

class adjList {
    private:
        string origin;
        vector<string> destinations;
        vector<Information> info;
    public:
        adjList();
        adjList(string);
        void print();
        void addDestination(string,Information);
        string getOrigin();
};

adjList::adjList() {
    origin = "N/E";
}

adjList::adjList(string origin) {
    this->origin = origin;
}

void adjList::print() {
    cout << "Origin: " << origin << endl <<
    "Destinations\n";
    cout.fill('-');
    cout.width(30);
    cout << "" << endl;
    for(int c = 0;c < destinations.size();c++) {
        cout << "Destination " << c + 1 << ": " << destinations[0] << endl;
        info[0].print(); 
    }
    cout << endl;
}

void adjList::addDestination(string destination,Information data) {
    destinations.push_back(destination);
    info.push_back(data);
}

string adjList::getOrigin() {
    return origin;
}