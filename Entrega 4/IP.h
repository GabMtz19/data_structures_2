#include <iostream>
using namespace std;

template<class T>
struct IP {
    T data;
    int numericValue;
    IP();
    IP(T);
    bool operator==(IP<T>);
};

template<class T>
IP<T>::IP() {
    numericValue = 0;
}

template<class T>
IP<T>::IP(T data) {
    this->data = data;
    int position = 0;
    string tempValue = "";
    while(position >= 0) {
        position = data.find('.');
        tempValue += data.substr(0,position);
        data.erase(0,position + 1);
    }
    numericValue = atoi(tempValue.c_str());
}

template<class T>
bool IP<T>::operator==(IP<T> comparison) {
    return data == comparison.data;
}