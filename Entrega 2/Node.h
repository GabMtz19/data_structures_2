#include "Atributes.h"
using namespace std;

struct Node {
    Node* next;
    Node* previous;
    Atributes data;
    Node();
    Node(Atributes);
    Node(Atributes,Node*);
    Node(Node*,Atributes);
};

Node::Node() {
    next = NULL;
    previous = NULL;
}

Node::Node(Atributes data) {
    previous = NULL;
    this->data = data;
    next = NULL;
}

Node::Node(Atributes data,Node* next) {
    previous = NULL;
    this->data = data;
    this->next = next;
}

Node::Node(Node* previous,Atributes data) {
    this->previous = previous;
    this->data = data;
    next = NULL;
}