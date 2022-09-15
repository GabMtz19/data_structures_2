#include "Stack.h"
using namespace std;

struct DoublyLL {
    Node* head;
    Node* tail;
    int size;
    DoublyLL();
    void add(Atributes);
    void merge(int,int,int);
    void mergeSort(int,int);
    Atributes operator[](int);
    void print();
};

DoublyLL::DoublyLL() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void DoublyLL::add(Atributes data) {
    if(size != 0) {
        tail->next = new Node(tail,data);
        tail = tail->next;
    }
    else {
        head = new Node(data);
        tail = head;
    }
    size++;
}

Atributes DoublyLL::operator[](int position) {
    Node* aux = head;
    for(int c = 0;c < position;c++) {
        aux = aux->next;
    }
    return aux->data;
}

void DoublyLL::merge(int low,int mid,int high) {
    int length = high - low + 1;
    int i = low;
    int j = mid + 1;
    int k = length - 1;
    Stack elements;
    while(length--) {
        Atributes I,J;
        if(i <= mid) {
            I = (*this)[i];
        }
        if(j <= high) {
            J = (*this)[j];
        }
        if(i <= mid && j <= high) {
            if(I.overallTime < J.overallTime) {
                elements.push(I);
                i++;
            }
            else {
                elements.push(J);
                j++;
            }
        }
        else if(i <= mid) {
            elements.push(I);
            i++;
        }
        else {
            elements.push(J);
            j++;
        }
    }
    for(int c = k;c >= 0;c--) {
        (*this)[low + c] = elements.pop();
    }
}

void DoublyLL::mergeSort(int low,int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(low,mid);
        mergeSort(mid + 1,high);
        merge(low,mid,high);
    }
}

void DoublyLL::print() {
    Node* aux = head;
    while(aux != NULL) {
        aux->data.print();
        aux = aux->next;
    }
}