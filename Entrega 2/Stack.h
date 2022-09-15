#include "Node.h"
using namespace std;

struct Stack {
    Node* head;
    int size;
    Stack();
    void push(Atributes);
    Atributes pop();
    void clear();
    void print();
    Atributes operator[](int);
};

Stack::Stack() {
    head = NULL;
    size = 0;
}

void Stack::push(Atributes data) {
    head = new Node(data,head);
    size++;
}

Atributes Stack::pop() {
    Atributes data = head->data;
    Node* aux = head;
    head = head->next;
    delete aux;
    size--;
    return data;
}

void Stack::clear() {
    while(head != NULL) {
        Node* aux = head;
        head = head->next;
        delete aux;
    }
}

void Stack::print() {
    Node* aux = head;
    while(aux != NULL) {
        aux->data.print();
        aux = aux->next;
    }
}

Atributes Stack::operator[](int position) {
    Node* aux = head;
    for(int c = 0;c < position;c++) {
        aux = aux->next;
    }
    return aux->data;
}