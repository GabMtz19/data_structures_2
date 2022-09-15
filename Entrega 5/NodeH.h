#include <iostream>
using namespace std;

struct NodeH {
    string element;
    int key;
    NodeH();
    NodeH(string,int);
};

NodeH::NodeH() {
    key = 0;
}

NodeH::NodeH(string element,int key) {
    this->element = element;
    this->key = key;
}