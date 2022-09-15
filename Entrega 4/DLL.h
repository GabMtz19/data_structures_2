#include "QueueP.h"

template<class T>
class DLL {
private:
    NodeP<T>* head;
    NodeP<T>* tail;
    int size;
    void mergeSort(int ini, int fin);
    void merge(int ini, int mid, int fin);
public:
    DLL();
    void operator=(initializer_list<T> list);
    void operator=(DLL<T> list);
    EdgeP<T>& operator[](int index);
    void addFirst(EdgeP<T> data);
    void addLast(EdgeP<T> data);
    bool deleteData(EdgeP<T> data); 
    bool deleteAt(int index); 
    void deleteLast();
    EdgeP<T> getData(int index); 
    NodeP<T>* getPointer(int index); 
    EdgeP<T> getHead(); 
    EdgeP<T> getTail(); 
    void updateAt(int index, EdgeP<T> newData);
    void updateData(EdgeP<T> data, EdgeP<T> newData);
    void insertAt(int index, EdgeP<T> newData);
    void duplicate();
    void removeDuplicates();
    int findData(EdgeP<T> data);
    int lowerBound(EdgeP<T> data);
    int upperBound(EdgeP<T> data);
    void sort();
    void clear();
    void print();
    void printReverse();
    bool isEmpty();
    int getSize();
};

template<class T>
DLL<T>::DLL() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
EdgeP<T>& DLL<T>::operator[](int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            NodeP<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeP<T>* aux = tail;
            int i = size; // The list starts with 1
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
void DLL<T>::operator=(initializer_list<T> list) {
    if (isEmpty()) {
        for (T i : list) {
            IP<T> node(i);
            addLast(node);
        }
    } else {
        throw runtime_error("Error: DLL no esta vacia");   
    }
}

template<class T>
void DLL<T>::operator=(DLL<T> list) {
    clear();
    for (int i=1; i<=list.size; i++) {
        addLast(list[i]);
    }

}

template<class T>
void DLL<T>::addFirst(EdgeP<T> data) {
    if (!isEmpty()) {
        head->prev = new NodeP<T>(data, head, NULL); 
        head = head->prev;
    } else {
        head = new NodeP<T>(data);
        tail = head;
    }
    size++;
}

template<class T>
void DLL<T>::addLast(EdgeP<T> data) {
    if (!isEmpty()) {
        tail->next = new NodeP<T>(data, tail->next, tail);
        tail = tail->next;
    } else {
        tail = new NodeP<T>(data);
        head = tail;
    }
    size++;
}

template<class T>
bool DLL<T>::deleteData(EdgeP<T> data) {
    if (!isEmpty()) {
        if (head->data == data) {
            NodeP<T>* aux = head;
            head = aux->next;
            head->prev = NULL;
            delete aux; // Libera espacio de memoria
            size--;
            if (head == NULL) {
                tail = NULL;
            }
            return true;
        } else {
            if (head->next != NULL) {
                NodeP<T>* aux = head->next;
                NodeP<T>* prev = head;
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
    }
    return false;
}

template<class T>
bool DLL<T>::deleteAt(int index) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            NodeP<T>* aux = head;
            head = aux->next;
            head->prev = NULL;
            delete aux;
            size--;
            if (head == NULL) {
                tail = NULL;
            }
            return true;
        } else {
            if (head->next != NULL) {
                NodeP<T>* aux = head->next;
                NodeP<T>* prev = head;
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
void DLL<T>::deleteLast(){
    if (!isEmpty()){
        NodeP<T>* aux = tail;
        tail = tail->prev;
        if (tail == NULL){ //if the list is emptied
            head = NULL;
        }
        delete aux;
        size--;
    }
}

template<class T>
EdgeP<T> DLL<T>::getData(int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            NodeP<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeP<T>* aux = tail;
            int i = size; // The list starts with 1
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
NodeP<T>* DLL<T>::getPointer(int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            NodeP<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeP<T>* aux = tail;
            int i = size; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux;
                }
                aux = aux->prev;
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
EdgeP<T> DLL<T>::getHead() {
    if (!isEmpty()) {
        return head->data;
    }
    throw out_of_range("Invalid position");
}

template<class T>
EdgeP<T> DLL<T>::getTail() {
    if (!isEmpty()) {
        return tail->data;
    }
    throw out_of_range("Invalid position");
}

template<class T>
void DLL<T>::updateAt(int index, EdgeP<T> newData) {
    if (index >= 1 && index <= size) {
        if (index <= size/2) {
            NodeP<T>* aux = head;
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
            NodeP<T>* aux = tail;
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
void DLL<T>::updateData(EdgeP<T> data, EdgeP<T> newData) {
    NodeP<T>* aux = head;
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
void DLL<T>::insertAt(int index, EdgeP<T> newData) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            head->prev = new NodeP<T>(newData,head,NULL);
            head = head->prev;
            size++;
            return;
        } else {
            if (index == size) {
                tail->next = new NodeP<T>(newData, NULL, tail);
                tail = tail->next;
                size++;
                return;
            } else {
                NodeP<T>* aux = head->next;
                NodeP<T>* prev = head;
                int i = 2;
                while(aux->next != NULL) {
                    if (i == index) {
                        prev->next = new NodeP<T>(newData,aux,prev);
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
void DLL<T>::merge(int ini, int mid, int fin) {
    QueueP<T> listL;
    QueueP<T> listR;
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
void DLL<T>::mergeSort(int ini, int fin) {
    if (ini < fin) {
        int mid = (ini + fin) / 2;
        mergeSort(ini,mid);
        mergeSort(mid+1,fin);

        merge(ini,mid,fin);
    }
}

template<class T>
void DLL<T>::sort() {
    mergeSort(1,size);
}

template<class T>
int DLL<T>::findData(EdgeP<T> data) {
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
int DLL<T>::lowerBound(EdgeP<T> data) {
    if (!isEmpty()) {
        int ini = 1;
        int fin = size;
        int mid;
        if (data <= getHead()) {
            return 1;
        }
        if (data <= getTail()) {
            while (ini < fin) {
                mid = (ini + fin) / 2;
                NodeP<T>* aux = getPointer(mid);
                if (aux->data > data) {
                    if (aux->prev->data < data) {
                        return mid;
                    } else {
                        if (aux->prev->data == data) {
                            return mid-1;
                        } else {
                            fin = mid-1;
                        }
                    }
                } else {
                    if (aux->data < data) {
                        if (aux->next->data >= data) {
                            return mid+1;
                        } else {
                            ini = mid+1;
                        }
                    } else {
                        return mid;
                    }
                }
            }
        }
    } 
    throw out_of_range("No hay datos en ese rango");
}

template<class T>
int DLL<T>::upperBound(EdgeP<T> data) {
    if (!isEmpty()) {
        int ini = 1;
        int fin = size;
        int mid;
        if (data >= getTail()) {
            return fin;
        }
        if (data >= getHead()) {
            while (ini < fin) {
                mid = (ini + fin) / 2;
                NodeP<T>* aux = getPointer(mid);
                if (aux->data > data) {
                    if (aux->prev->data < data) {
                        return mid-1;
                    } else {
                        if (aux->prev->data == data) {
                            return mid-1;
                        } else {
                            fin = mid-1;
                        }
                    }
                } else {
                    if (aux->data < data) {
                        if (aux->next->data > data) {
                            return mid;
                        } else {
                            if (aux->next->data == data) {
                                return mid+1;
                            } else {
                                ini = mid+1;
                            }
                        }
                    } else {
                        return mid;
                    }
                }
            }
        }
    } 
    throw out_of_range("No hay datos en ese rango");
}

template<class T>
void DLL<T>::duplicate() {
    // NodeP<T>* aux = head;
    // while (aux != NULL) {
    //     aux->next = new NodeP<T>(aux->data,aux->next);
    //     size++;
    //     aux = aux->next->next;
    // }
}

template<class T>
void DLL<T>::removeDuplicates() {
    // NodeP<T>* aux = head;
    // DLL<T> list = *this;
    // clear();
    // for (int i=1; i<list.size; i++) {
    //     if (!findData(aux->data)) {
    //         addLast(aux->data);
    //     }
    // }
}

template<class T>
void DLL<T>::print() {
    NodeP<T>* aux = head;
    for (int i=1; i<=size; i++) {
        aux->data.print();
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
void DLL<T>::printReverse() {
    NodeP<T>* aux = tail;
    for (int i=size; i>=1; i--) {
        aux->data.print();
        aux = aux->prev;
    }
    cout << endl;
}

template<class T>
void DLL<T>::clear() {
    int i = 1;
    while (i<=size) {
        NodeP<T>* aux = head;
        head = aux->next;
        delete aux;
        i++;
    }
    size = 0;
    tail = NULL;
}

template<class T>
bool DLL<T>::isEmpty() {
    return size == 0;
}

template<class T>
int DLL<T>::getSize() {
    return size;
}