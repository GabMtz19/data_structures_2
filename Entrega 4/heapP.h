#ifndef heapP_h
#define heapP_h

#include "DLL.h"

template<class T>
class heapP {
private:
    DLL<T> heap;
    int size;
    void downSort(int index);
    void swap(int a, int b);
    void upSort();
public:
    heapP();
    heapP(DLL<T> list);
    EdgeP<T> remove();
    void insert(EdgeP<T> data);
    bool isEmpty();
    void print();
};

template<class T>
heapP<T>::heapP() {
    size = 0;
}

template<class T>
void heapP<T>::swap(int a, int b) {
    EdgeP<T> aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template<class T>
void heapP<T>::downSort(int index) {
    while (index >= 1) {
        int pos = index;
        while (pos*2<=size) {
            int s1 = pos * 2;
            int s2 = pos * 2 + 1;
            int max;
            if (s2 > size) {
                max = s1;
            } else {
                heap[s1].numEdges > heap[s2].numEdges ? max = s1 : max = s2;
            }
            if (heap[max].numEdges > heap[pos].numEdges) {
                swap(pos,max);
                pos = max; // Para comparar el hijo con sus hijo
            } else {
                pos = size; // Salir del ciclo
            }
        }
        index--;
    }
}


template<class T>
EdgeP<T> heapP<T>::remove() {
    if (!isEmpty()) {
        EdgeP<T> aux = heap[1];
        swap(1,size);
        heap.deleteLast();
        size--;
        downSort(1);
        return aux;
    }
    throw runtime_error("The Heap is empty");
}

template<class T>
void heapP<T>::upSort() {
    int pos = size;
    while (pos > 1) {
        int father = pos / 2;
        if (heap[pos].numEdges > heap[father].numEdges) {
            swap(father, pos);
            pos = father;
        } else {
            pos = 1; // para salir del ciclo
        }
    }
}

template<class T>
void heapP<T>::insert(EdgeP<T> data) {
    heap.addLast(data);
    size++;
    upSort();
}

template<class T>
heapP<T>::heapP(DLL<T> list) {
    if (!list.isEmpty()) {
        heap = list;
        size = heap.getSize();
        int index = size / 2;
        downSort(index);
    } else {
        size = 0;
    }
}

template<class T>
bool heapP<T>::isEmpty() {
    return size == 0;
}

template<class T>
void heapP<T>::print() {
    heap.print();
}

#endif