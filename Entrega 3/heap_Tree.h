#include "DoublyLinkedList.h"
using namespace std;

template<class T>
struct heap {

    DoublyLinkedList<T> heap_tree;
    int size;

    void downSort(int);
    void swap(int,int);
    
    heap();
    heap(DoublyLinkedList<T>);
    T remove();
    void insert(T);
    bool isEmpty();
    void print();
};

template<class T>
heap<T>::heap() {
    size = 0;
}

template<class T>
heap<T>::heap(DoublyLinkedList<T> linked_list) {
    if(linked_list.getSize() != 0) {
        heap_tree = linked_list;
        size = linked_list.getSize();
        int index = linked_list.getSize() / 2;  
        downSort(index);
    }
    else {
        heap();
    }
}

template<class T>
void heap<T>::downSort(int index) {
    while(index >= 1) {
        int pos = index;
        while(pos*2 <= size) {
            int s1 = pos * 2;
            int s2 = pos * 2 + 1;
            int max;
            if(s2 > size) {
                max = s1;
            }
            else {
                heap_tree[s1] > heap_tree[s2] ? max = s1 : max = s2;
            }
            if(heap_tree[max] > heap_tree[pos]) {
                swap(pos,max);
                pos = max;
            }
            else {
                pos = size;
            }
        }
        index--;
    }
}

template<class T>
void heap<T>::swap(int a,int b) {
    T aux = heap_tree[a];
    heap_tree[a] = heap_tree[b];
    heap_tree[b] = aux;
}

template<class T>
void heap<T>::print() {
    heap_tree.print();
}

template<class T>
T heap<T>::remove() {
    if(!isEmpty()) {
        T aux = heap_tree[1];
        swap(1,size);
        heap_tree.deleteAt(size);
        size--;
        downSort(size);
        return aux;
    }
    else {
        throw runtime_error("The heap is empty \n");
    }
}

template<class T>
void heap<T>::insert(T data) {
    if(!isEmpty()) {
        heap_tree.addLast(data);
        size++;
        downSort(size);
    }
    else {
        heap_tree.addFirst(data);
        size++;
    }
}

template<class T>
bool heap<T>::isEmpty() {
    return size==0;
}