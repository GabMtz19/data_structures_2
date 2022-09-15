#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "Queue.h"
using namespace std;

template<class T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    Queue<T> ips;
    int size;
    void mergeSort(int,int);
    void merge(int,int,int);
    void verifyUnique(T);
public:
    DoublyLinkedList();
    void operator=(initializer_list<T>);
    void operator=(DoublyLinkedList<T>);
    T& operator[](int);
    void addFirst(T);
    void addLast(T);
    bool deleteData(T); 
    bool deleteAt(int); 
    T getData(int); 
    Queue<T> getQueue();
    void updateAt(int,T);
    void updateData(T,T);
    void insertAt(int,T);
    void duplicate();
    void removeDuplicates();
    int findData(T);
    void sort();
    void clear();
    void print();
    void printReverse();
    bool isEmpty();
    int getSize();
    NodeD<T>* getHead();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
T& DoublyLinkedList<T>::operator[](int position) {
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

template<class T>
void DoublyLinkedList<T>::operator=(initializer_list<T> list) {
    if (isEmpty()) {
        for (T data : list) {
            addLast(data);
        }
    } 
    else {
        throw runtime_error("\nError: Doubly Linked List isn't empty \n");   
    }
}

template<class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list) {
    clear();
    for (int c = 1;c <= list.size;c++) {
        addLast(list[c]);
    }
}

template<class T>
void DoublyLinkedList<T>::addFirst(T data) {
    if (!isEmpty()) {
        head->prev = new NodeD<T>(data, head, NULL); 
        head = head->prev;
    } 
    else {
        head = new NodeD<T>(data);
        tail = head;
    }
    verifyUnique(data);
    size++;
}

template<class T>
void DoublyLinkedList<T>::addLast(T data) {
    if (!isEmpty()) {
        tail->next = new NodeD<T>(data,NULL,tail);
        tail = tail->next;
    } 
    else {
        tail = new NodeD<T>(data);
        head = tail;
    }
    verifyUnique(data);
    size++;
}

template<class T>
void DoublyLinkedList<T>::verifyUnique(T data) {
    NodeD<T>* aux = ips.getHead();
    while(aux != NULL) {
        if(aux->data == data) {
            aux->data.addRep();
            return;
        }
        else {
            aux = aux->next;
        }
    }
    ips.enqueue(data);
}

template<class T>
bool DoublyLinkedList<T>::deleteData(T data) {
    if (!isEmpty()) {
        if (head->data == data) {
            NodeD<T>* aux = head;
            head = aux->next;
            head->prev = NULL;
            delete aux;
            if (head == NULL) {
                tail = NULL;
            }
            return true;
        } 
        else {
            if (head->next != NULL) {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                while (aux != NULL) {
                    if (aux->data == data) {
                        prev->next = aux->next;
                        if (aux->next != NULL) {
                            aux->next->prev = prev;
                        } else {
                            tail = prev;
                        }
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux->next;
                    }
                }
            }
        }
        size--;
    }
    return false;
}

template<class T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            NodeD<T>* aux = head;
            head = aux->next;
            if (head == NULL) {
                tail = NULL;
            } else {
                head->prev = NULL;
            }
            delete aux;
            size--;
            return true;
        } else {
            if (head->next != NULL) {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                int i = 2;
                while (aux != NULL) {
                    if (i == index) {
                        prev->next = aux->next;
                        if (aux->next != NULL) {
                            aux->next->prev = prev;
                        } else {
                            tail = prev;
                        }
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux->next;
                    }
                    i++;
                }
            }
        }
    }
    return false;
}

template<class T>
T DoublyLinkedList<T>::getData(int index) {
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
Queue<T> DoublyLinkedList<T>::getQueue() {
    return ips;
}

template<class T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
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
void DoublyLinkedList<T>::updateData(T data, T newData) {
    NodeD<T>* aux = head;
    while(aux != NULL) {
        if (aux->data == data) {
            aux->data = newData;
            return;
        }
        aux = aux->next;
    }
    throw out_of_range("Data not found");
}

template<class T>
void DoublyLinkedList<T>::insertAt(int index, T newData) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            head->prev = new NodeD<T>(newData,head,NULL);
            head = head->prev;
            size++;
            return;
        } else {
            if (index == size) {
                tail->next = new NodeD<T>(newData, NULL, tail);
                tail = tail->next;
                size++;
                return;
            } else {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                int i = 2;
                while(aux->next != NULL) {
                    if (i == index) {
                        prev->next = new NodeD<T>(newData,aux,prev);
                        size++;
                        return;
                    }
                    prev = aux;
                    aux = aux->next;
                    i++;
                }
            }
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
void DoublyLinkedList<T>::merge(int ini, int mid, int fin) {
    Queue<T> listL;
    Queue<T> listR;
    int pos,f1,f2,i,j;
    pos = ini;
    f1 = mid - ini + 1;
    f2 = fin - mid;   
    for (i=1;i<=f1;i++) {
        listL.enqueue(getData(ini+i-1));
    }
    for (j=1;j<=f2;j++) {
        listR.enqueue(getData(mid+1+j-1));
    }
    i = 1;
    j = 1;
    while (i<=f1 && j<=f2) {
        if (listL.front()<=listR.front()) {
            updateAt(pos,listL.dequeue());
            i++;
        } else {
            updateAt(pos,listR.dequeue());
            j++;
        }
        pos++;
    }
    while (i<=f1) {
        updateAt(pos,listL.dequeue());
        i++;
        pos++;
    }
    while (j<=f2) {
        updateAt(pos,listR.dequeue());
        j++;
        pos++;
    }
}

template<class T>
void DoublyLinkedList<T>::mergeSort(int ini, int fin) {
    if (ini < fin) {
        int mid = (ini + fin) / 2;
        mergeSort(ini,mid);
        mergeSort(mid+1,fin);

        merge(ini,mid,fin);
    }
}

template<class T>
void DoublyLinkedList<T>::sort() {
    mergeSort(1,size);
}

template<class T>
int DoublyLinkedList<T>::findData(T data) {
    int posI = 1;
    int posF = size;
    int posM = (posI + posF) / 2;
    bool found = false;
    sort();
    while (posI <= posF && !found) {
        if (data < getData(posM)) {
            posF = posM - 1;
        } else {
            if (data > getData(posM)) {
                posI = posM + 1;
            } else {
                if (data == getData(posM)) {
                    found = true;
                }
            }
        }
        posM = (posI + posF) / 2;
    }
    if (found) {
        return posM;
    } else {
        throw runtime_error("Not found in list");
    }
}

template<class T>
void DoublyLinkedList<T>::duplicate() {
    NodeD<T>* aux = head;
    while (aux != NULL) {
        aux->next = new NodeD<T>(aux->data,aux->next);
        size++;
        aux = aux->next->next;
    }
}

template<class T>
void DoublyLinkedList<T>::removeDuplicates() {
    NodeD<T>* aux = head;
    DoublyLinkedList<T> list = *this;
    clear();
    for (int i=1; i<list.size; i++) {
        if (!findData(aux->data)) {
        addLast(aux->data);
        }
    }
}

template<class T>
void DoublyLinkedList<T>::print() {
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        aux->data.print();
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
void DoublyLinkedList<T>::printReverse() {
    NodeD<T>* aux = tail;
    for (int i=size; i>=1; i--) {
        cout << aux->data << " ";
        aux = aux->prev;
    }
    cout << endl;
}

template<class T>
void DoublyLinkedList<T>::clear() {
    int i = 1;
    while (i<=size) {
        NodeD<T>* aux = head;
        head = aux->next;
        delete aux;
        i++;
    }
    size = 0;
    tail = NULL;
    ips.clear();
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}

template<class T>
int DoublyLinkedList<T>::getSize() {
    return size;
}

template<class T>
NodeD<T>* DoublyLinkedList<T>::getHead() {
    return head;
}
#endif