#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// This class will represent one entry in the phonebook
class Entry {
    // Don't forget, that these member variables are inaccessible from outside of objects of this class
    string name;
    int number;
public:
    Entry* next;
    
    // Constructor
    Entry(string newName, int newNumber) {
        name = newName;
        number = newNumber;
    }
    
    string getName() {
        return name;
    }
    
    int getNumber() {
        return number;
    }
    
    void setNumber(int newNumber) {
        number = newNumber;
    }
};

// This class represents a whole PhoneBook
class Phonebook {
    // We will sotre all entries in a linked list
    Entry* firstEntry;
    
public:
    // Constructor
    Phonebook() {
        firstEntry = 0;
    }
    
    // Destructor
    ~Phonebook() {
        Entry* current = firstEntry;
        while (current != 0) {
            Entry* tmp = current->next;
            delete current;
            current = tmp;
        }
    }
};

int main(int argc, char** argv) {
    Phonebook p;
    
    return 0;
}

