#include <iostream>
#include <fstream>
using namespace std;

struct Atributes {
    string month,ip_address,fail;
    int day,hour,minute,second,overall_time;
    Atributes();
    Atributes(string,int,int,int,int,string,string,int);
    void print();
};

Atributes::Atributes() {
    month = " ";
    ip_address = " ";
    fail = " ";
    day = 0;
    hour = 0;
    minute = 0;
    second = 0;
}

Atributes::Atributes(string month,int day,int hour,int minute,int second,string ip_address,string fail,int overall_time) {
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->ip_address = ip_address;
    this->fail = fail;
    this->overall_time = overall_time;
}

void Atributes::print() {
    cout << month << " " << day << " " << hour << ":" << minute << ":" << second << " " << ip_address << fail << endl;
}

struct Node {
    Node* next;
    Node* previous;
    Atributes entry_atributes;
    Node();
    Node(Atributes);
    Node(Atributes,Node*);
    Node(Node*,Atributes);
    Node(Node*,Atributes,Node*);
};

Node::Node() {
    next = NULL;
    previous = NULL;
}

Node::Node(Atributes entry_atributes) {
    this->entry_atributes = entry_atributes;
}

Node::Node(Atributes entry_atributes,Node* next) {
    previous = NULL;
    this->entry_atributes = entry_atributes;
    this->next = next;
}

Node::Node(Node* previous,Atributes entry_atributes) {
    this->previous = previous;
    this->entry_atributes = entry_atributes;
    next = NULL;
}

Node::Node(Node* previous,Atributes entry_atributes,Node* next) {
    this->previous = previous;
    this->entry_atributes = entry_atributes;
    this->next = next;
}

struct DoubleyLL {
    Node* head;
    Node* tail;
    int size;
    DoubleyLL();
    void add(Atributes);
    void replace(int,Atributes);
    Atributes operator[](int);
    void print();
};

DoubleyLL::DoubleyLL() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void DoubleyLL::add(Atributes entry_atributes) {
    if(size != 0) {
        tail->next = new Node(tail,entry_atributes);
        tail = tail->next;
    }
    else {
        head = new Node(entry_atributes);
        tail = head;
    }
    size++;
}

Atributes DoubleyLL::operator[](int position) {
    Node* aux = head;
    for(int c = 0;c < position;c++) {
        aux = aux->next;
    }
    return aux->entry_atributes;
}

void DoubleyLL::print() {
    Node* aux = head;
    while(aux != NULL) {
        aux->entry_atributes.print();
        aux = aux->next;
    }
}

void DoubleyLL::replace(int position,Atributes entry_atributes) {
    Node* aux = head;
    for(int c = 0;c < position;c++) {
        aux = aux->next;
    }
    aux->entry_atributes = entry_atributes;
}

struct Stack {
    Node* head;
    int size = 0;
    Stack();
    void push(Atributes);
    Atributes operator[](int);
};

Stack::Stack() {
    head = NULL;
    size = 0;
}

void Stack::push(Atributes entry_atributes) {
    head = new Node(entry_atributes,head);
}

Atributes Stack::operator[](int position) {
    Node* aux = head;
    for(int c = 0;c < position;c++) {
        aux = aux->next;
    }
    return aux->entry_atributes;
}

int obtainTime(string month,int day,int hour,int minute,int second) {
    string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int sec_month;
    for(int c = 1;c < 13;c++) {
        if(months[c] == month) {
            sec_month = c + 2678400;
            break;
        }
    }
    day *= 86400;
    hour *= 3600;
    minute *= 60;
    return sec_month + day + hour + minute + second;
}

void readFile(DoubleyLL& doubleLL) {
    string month,time,ip_address,fail;
    int day;
    ifstream myfile;
    myfile.open("Entrega 2/bitacora.txt");
    while(! myfile.eof()) {
        myfile >> month >> day >> time >> ip_address;
        getline(myfile,fail);
        int position = time.find(':');
        int hour = atoi(time.substr(0,position).c_str());
        time.erase(0,position + 1);
        position = time.find(':');
        int minute = atoi(time.substr(0,position).c_str());
        time.erase(0,position + 1);
        int second = atoi(time.c_str());
        int overall_time = obtainTime(month,day,hour,minute,second);
        Atributes entry_atributes(month,day,hour,minute,second,ip_address,fail,overall_time);
        doubleLL.add(entry_atributes);
    }
}

void merge(DoubleyLL &doubleLL,int low,int mid,int high) {
    int left_part = mid - low + 1;
    int right_part = high - mid;
    Stack left_elements;
    Stack right_elements;
    for(int c = 0;c < left_part;c++) {
        left_elements.push(doubleLL[low + c]);
    }
    for(int c = 0;c < right_part;c++) {
        right_elements.push(doubleLL[mid + 1 + c]);
    }
    int left = 0;
    int right = 0;
    int general = low;
    while(left < left_part && right < right_part) {
        if(left_elements[left].overall_time <= right_elements[right].overall_time) {
            doubleLL.replace(general,left_elements[left]);
            general++;
            left++;
        }
        else {
            doubleLL.replace(general,right_elements[right]);
            general++;
            right++;
        }
    }
    while(left < left_part) {
        doubleLL.replace(general,left_elements[left]);
        general++;
        left++;
    }
    while(right < right_part) {
        doubleLL.replace(general,right_elements[right]);
        general++;
        right++;
    }
}

void mergeSort(DoubleyLL doubleLL,int low,int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(doubleLL,low,mid);
        mergeSort(doubleLL,mid + 1,high);
        merge(doubleLL,low,mid,high);
    }
}

void createFile(DoubleyLL doubleLL,int size) {
    ofstream new_file("Entrega 2/Entries.txt");
    for(int c = 0;c < size;c++) {
        string date = doubleLL[c].month + " " + to_string(doubleLL[c].day) + " ";
        string hour = to_string(doubleLL[c].hour) + ":" + to_string(doubleLL[c].minute) + ":" + to_string(doubleLL[c].second) + " ";
        new_file << date << hour << doubleLL[c].ip_address << doubleLL[c].fail;
        if(c != size - 1) {
            new_file << endl;
        }
    }
}

int main() {
    DoubleyLL doubleLL;
    readFile(doubleLL);
    mergeSort(doubleLL,0,doubleLL.size - 1);
    doubleLL.print();
    createFile(doubleLL,doubleLL.size);
    return 0;
}