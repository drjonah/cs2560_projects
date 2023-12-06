/*
 * Jonah Lysne
 * Professor Haung
 * Project 4: Due Dec 6, 2023
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Warehouse.h"
#include "Book.h"
using namespace std;

bool parseFile(string filename, Warehouse* warehouse);
void displayParams();

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 4) {
        // invalid parameter input 
        cerr << "Invalid program parameters:" << endl;
        displayParams();
        return -1;
    }

    string filename = argv[1], command = argv[2], id; // format input
    Warehouse* warehouse = new Warehouse();

    // ./proj04 <input file> list
    if (argc == 3 && command == "list") {
        if (parseFile(filename, warehouse)) 
            cout << warehouse;
        else {
            cerr << "Error: book parsing failed. Ensure that the book data is correct." << endl;
            cerr << "       (common errors occur with numerical data)" << endl;
            delete warehouse; // deletes warehouse
            return -1;
        }
    }

    // ./proj04 <input file> find <id>
    else if (argc == 4 && command == "find") {
        if (!parseFile(filename, warehouse)) {
            cerr << "Error: book parsing failed." << endl;
            return -1;
        }

        id = argv[3];
        Book* book = nullptr;
        book = warehouse->find(id);
        
        if (book != nullptr) {
            cout << "ISBN: " << id << " -- FOUND" << endl;
            cout << book;
        }
        else 
            cout << "ISBN: " << id << " -- NOT FOUND" << endl;
    }
    
    else {
        cerr << "Error: invalid command" << endl;
        displayParams();
        delete warehouse; // deletes warehouse
        return -1;
    }

    delete warehouse; // deletes warehouse

    return 0;
}

bool parseFile(string filename, Warehouse* warehouse) {
    ifstream file;
    file.open(filename); // open file

    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return false; // Indicate failure
    }

    // get(): used to see if a next char can be fetched (returns char or EOF)
    // char version of getline
    char check;
    while(file.get(check)) {
        file.putback(check);
        if (!(file >> warehouse)) {
            file.close();
            return false;
        }
    }

    file.close(); 
    return true;
}

void displayParams() {
    cout << "    ./proj04 <input file> list" << endl;
    cout << "    ./proj04 <input file> find <id>" << endl;
}