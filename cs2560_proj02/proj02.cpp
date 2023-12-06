/*
 * Jonah Lysne
 * Professor Haung
 * Project 2: Due Nov 1, 2023
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Warehouse.h"
#include "Book.h"
using namespace std;

bool parseFile(string filename, Warehouse& warehouse);
void displayParams();

int main(int argc, char *argv[]) {

    if (argc != 3 && argc != 4) {
        // invalid parameter input 
        cerr << "Invalid program parameters:" << endl;
        displayParams();
        return -1;
    }

    string filename = argv[1], command = argv[2], id; // format input
    Warehouse warehouse;

    // ./proj02 <input file> list
    if (argc == 3 && command == "list") {
        if (parseFile(filename, warehouse)) 
            cout << warehouse;
        else {
            cerr << "Error: book parsing failed." << endl;
            return -1;
        }
    }

    // ./proj02 <input file> find <id>
    else if (argc == 4 && command == "find") {
        if (!parseFile(filename, warehouse)) {
            cerr << "Error: book parsing failed." << endl;
            return -1;
        }

        id = argv[3];
        Book book;
        
        if (warehouse.find(id, book)) {
            cout << "ISBN: " << id << " -- FOUND" << endl;
            cout << book;
        }
        else 
            cout << "ISBN: " << id << " -- NOT FOUND" << endl;
    }
    else {
        cerr << "Error: invalid command" << endl;
        displayParams();
        return -1;
    }

    return 0;
}

bool parseFile(string filename, Warehouse& warehouse) {
    ifstream file;
    file.open(filename); // open file

    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return false; // Indicate failure
    }

    while(!file.eof()) {
        if (!(file >> warehouse)) {
            file.close(); 
            return false; 
        }
    }

    file.close(); 
    return true;
}

void displayParams() {
    cout << "    ./proj02 <input file> list" << endl;
    cout << "    ./proj02 <input file> find <id>" << endl;
}