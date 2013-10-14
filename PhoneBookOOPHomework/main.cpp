#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Entry {
    string name;
    int number;
public:
    Entry* next;

    Entry(string newName, int newNumber) {
        name = newName;
        number = newNumber;
        next = 0;
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

    void printEntry() {
        cout << name << ": " << number << endl;
    }
};

class Phonebook {
    Entry* firstEntry;
    Entry* lastEntry;

public:

    Phonebook() {
        firstEntry = 0;
        lastEntry = 0;
    }

    void printBook() {
        Entry* current = firstEntry;
        while (current != 0) {
            current->printEntry();
            current = current->next;
        }
    }

    void addEntry(string newName, int newNumber) {
        Entry* newEntry = new Entry(newName, newNumber);
        if (firstEntry == 0) {
            firstEntry = newEntry;
            lastEntry = newEntry;
        } else {
            lastEntry->next = newEntry;
            lastEntry = newEntry;
        }
    }

    ~Phonebook() {
        Entry* current = firstEntry;
        while (current != 0) {
            Entry* tmp = current->next;
            delete current;
            current = tmp;
        }
    }
};

int askChoice() {
    cout << "P H O N E   B O O K" << endl;
    cout << "1) Print book" << endl;
    cout << "2) Add entry" << endl;
    cout << "3) Remove entry" << endl;
    cout << "4) Change number" << endl;
    cout << "5) Find number" << endl;
    cout << "0) Exit" << endl;

    int choice;
    cin >> choice;
    return choice;
}

string askName() {
    cout << "Give me the name: ";
    string name;
    cin >> name;
    return name;
}

int askNumber() {
    cout << "Give me the number: ";
    int number;
    cin >> number;
    return number;
}

int main(int argc, char** argv) {
    Phonebook p;

    int choice;
    string name;
    int number;
    do {
        choice = askChoice();
        
        switch (choice) {
            case 0:
                break;
            case 1:
                p.printBook();
                break;
            case 2:
                name = askName();
                number = askNumber();
                p.addEntry(name, number);
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

