#include "hashTable.h"
#include <fstream>
using namespace std;

void readIps(int numIps,ifstream& myFile,hashTable& table) {
    string ip;
    for(int c = 0;c < numIps;c++) {
        myFile >> ip;
        table.addIp(ip);
    }
}

void readEdges(int numEdges,ifstream& myFile,hashTable& table) {

    string month,day,time,origin,destination,failureType;

    for(int c = 0;c < numEdges;c++) {

        myFile >> month >> day >> time >> origin >> destination;
        getline(myFile,failureType);
        string dateTime = month + " " + day + " " + time;
        int position = origin.find(':');
        string port1 = origin.substr(position,-1);
        origin.erase(position,-1);
        position = destination.find(':');
        string port2 = destination.substr(position,-1);
        destination.erase(position,-1);

        Information info(dateTime,failureType,port1,port2);

        try {
            table.addEdge(origin,destination,info);
        }
        catch(runtime_error error) {
            cout << error.what();
        }

    }

}

int main() {

    ifstream myFile;
    int numIps,numEdges;
    myFile.open("Entrega 5/bitacoraACT4_3.txt");
    myFile >> numIps >> numEdges;
    hashTable table(numIps);

    readIps(numIps,myFile,table);

    readEdges(numEdges,myFile,table);

    myFile.close();

    char option = 'Y';
    while(option == 'Y') {
        string ip;
        cout << "Enter the IP you're looking for: ";
        cin >> ip;
        try {
            table.printIp(ip);
        }
        catch(runtime_error error) {
            cout << error.what();
        }
        cout << "Do you wish to continue looking for IPs? \n" <<
        "Type 'Y' for yes or 'N' for no\n";
        cin >> option;
        while(option != 'Y' && option != 'N') {
            cout << "\n<<ERROR>>-->Invalid option\n" <<
            "Type 'Y' for yes or 'N' for no\n";
            cin >> option;
        }
        cout << endl;
    }

    cout << "\nThanks for using my program, see you later!\n";

    system("pause");
    return 0;

}