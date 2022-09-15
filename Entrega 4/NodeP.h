#include "EdgeP.h"
#include <stdio.h>
#include <string>
using namespace std;

template<class T>
struct NodeP{
    EdgeP<T> data;
    NodeP<T> *next;
    NodeP<T> *prev;
    
    NodeP(EdgeP<T>);
    NodeP(EdgeP<T>, NodeP<T>*, NodeP<T>*);
};

template<class T>
NodeP<T> :: NodeP(EdgeP<T> data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template<class T>
NodeP<T> :: NodeP(EdgeP<T> data, NodeP<T> *next, NodeP<T> *prev){
    this->data = data;
    this->next = next;
    this->prev = prev;
}
