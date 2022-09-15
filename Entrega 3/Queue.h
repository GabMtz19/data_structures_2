#ifndef Queue_h
#define Queue_h

#include "NodeD.h"
using namespace std;

template<class T>
class Queue{
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;
public:
    Queue();
    void enqueue(T);
    T dequeue();
    T front();
    T back();
    int getSize();
    NodeD<T>* getHead();
    T getData(int);
    void updateAt(int,T);
    void clear();
    void print();
    bool isEmpty();
    T& operator[](int);
};

template<class T>
Queue<T>::Queue() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
void Queue<T>::enqueue(T data) {
    NodeD<T>* aux = new NodeD<T>(data);
    if (isEmpty()) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
    size++;
}

template<class T>
T Queue<T>::dequeue() {
    T data;
    if (!isEmpty()) {
        NodeD<T>* aux = head;
        data = aux->data;
        head = aux->next;
        delete aux;
        size--;
        if (head == NULL) {
            tail = NULL;
        }
        return data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
T Queue<T>::back() {
    if (!isEmpty()) {
        return tail->data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
int Queue<T>::getSize() {
    return size;
}

template<class T>
NodeD<T>* Queue<T>::getHead() {
    return head;
}

template<class T>
void Queue<T>::clear() {
    while (head != NULL) {
        NodeD<T>* aux = head;
        head = aux->next;
        delete aux;
    }
    size = 0;
    tail = NULL;
}

template<class T>
void Queue<T>::print() {
    NodeD<T>* aux = head;
    while(aux != NULL) {
        aux->data.printUnique();
        aux = aux->next;
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

template<class T>
void Queue<T>::updateAt(int index, T newData) {
    if (index >= 1 && index <= size) {
        if (index <= size/2) {
            NodeD<T>* aux = head;
            int i = 1;
            while(aux != NULL) {
                if (i == index) {
                    aux->data = newData;
                    return;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeD<T>* aux = tail;
            int i = size;
            while(aux != NULL) {
                if (i == index) {
                    aux->data = newData;
                    return;
                }
                aux = aux->prev;
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
T Queue<T>::getData(int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            NodeD<T>* aux = head;
            int i = 1;
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeD<T>* aux = tail;
            int i = size;
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->prev;
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
T& Queue<T>::operator[](int position) {
    if (position > 0 && position <= size) {
        NodeD<T>* aux;
        if (position <= size / 2) {
            aux = head;
            for(int c = 1;c < position;c++) {
                aux = aux->next;
            }
            return aux->data;
        } 
        else {
            aux = tail;
            for(int c = size;c > position;c--) {
                aux = aux->prev;
            }
            return aux->data;
        }
    }
    throw out_of_range("\nOut_of_range_value \n");
}
#endif