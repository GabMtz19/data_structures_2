#include "adjList.h"
using namespace std;

class hashTable {
    private:
        vector<adjList> table;
        vector<int> status;
        int size;
        int hashing(string);
        int linearTest(int);
        int findIp(string);
    public:
        hashTable(int);
        void addIp(string);
        void print();
        void addEdge(string,string,Information);
        void printIp(string);
};

int hashTable::hashing(string ip) {
    string tempIp = "";
    for(auto character : ip) {
        if(character != '.') {
            tempIp += character;
        }
    }
    while(tempIp.size() != 12) {
        tempIp.insert(0,1,'0');
    }
    string keyStr = "";
    for(int c = 4;c <= 7;c++) {
        keyStr += tempIp[c];
    }
    int key = atoi(keyStr.c_str());
    key = key * key;
    return key % size;
}

int hashTable::linearTest(int index) {
    if(status[index] != 1) {
        return index;
    }
    else {
        while(status[index] == 1) {
            index++;
            if(index == size) {
                index = 0;
            }
        }
        return index;
    }
}

int hashTable::findIp(string ip) {
    int index = hashing(ip);
    int initialPos = index;
    while(status[index] != 0) {
        if(table[index].getOrigin() == ip) {
            return index;
        }
        else {
            index++;
            if(index == size) {
                index = 0;
            }
            else if(index == initialPos) {
                return -1;
            }
        }
    }
    return -1;
}

hashTable::hashTable(int size) {
    this->size = size;
    for(int c = 0;c < size;c++) {
        adjList tempList;
        table.push_back(tempList);
    }
    vector<int> tempStatus(size,0);
    status = tempStatus;
}

void hashTable::addIp(string ip) {
    int index = hashing(ip);
    int key = linearTest(index);
    adjList newList(ip);
    table[key] = newList;
    status[key] = 1;
}

void hashTable::print() {
    for(auto ip : table) {
        ip.print();
    }
    cout << endl;
}

void hashTable::addEdge(string origin,string destination,Information info) {
    
    int originIndex = findIp(origin);

    if(originIndex != -1) {
        table[originIndex].addDestination(destination,info);
    }
    else {
        throw runtime_error("<<ERROR>>-->IP was not found on the hash table\n");
    }

}

void hashTable::printIp(string ip) {

    int index = findIp(ip);

    if(index != -1) {
        table[index].print();
    }
    else {
        throw runtime_error("<<ERROR>>-->IP was not found on the hash table\n");
    }

}