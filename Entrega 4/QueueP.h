#include "NodeP.h"

template<class T>
class QueueP{
private:
    NodeP<T>* head;
    NodeP<T>* tail;
    int size;
public:
    QueueP();
    void enqueue(EdgeP<T> Data);
    EdgeP<T> dequeue();
    EdgeP<T> front();
    EdgeP<T> back();
    int getSize();
    void clear();
    void print();
    bool isEmpty();
};

template<class T>
QueueP<T>::QueueP() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
void QueueP<T>::enqueue(EdgeP<T> data) {
    NodeP<T>* aux = new NodeP<T>(data);
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
EdgeP<T> QueueP<T>::dequeue() {
    T data;
    if (!isEmpty()) {
        NodeP<T>* aux = head;
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
EdgeP<T> QueueP<T>::front() {
    if (!isEmpty()) {
        return head->data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
EdgeP<T> QueueP<T>::back() {
    if (!isEmpty()) {
        return tail->data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
int QueueP<T>::getSize() {
    return size;
}

template<class T>
void QueueP<T>::clear() {
    while (head != NULL) {
        NodeP<T>* aux = head;
        head = aux->next;
        delete aux;
    }
    size = 0;
    tail = NULL;
}

template<class T>
void QueueP<T>::print() {
    NodeP<T>* aux = head;
    while (aux != NULL) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}


template<class T>
bool QueueP<T>::isEmpty() {
    return size == 0;
}