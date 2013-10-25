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
		// At first, we create a new object of class Entry
        Entry* newEntry = new Entry(newName, newNumber);
		// If we are adding an entry to an empty phonebook,
		// we have to do ot in a different way
        if (firstEntry == 0) {
			// So we set the first entry...
            firstEntry = newEntry;
			// ... and since the very first one entry
			// will be as well the only one,
			// it will be also the last one.
            lastEntry = newEntry;
        } else {
			// The additional entries
			// (others than the first one)
			// will be appended to the end of the list
            lastEntry->next = newEntry;
            lastEntry = newEntry;
        }
    }

	void removeEntry(string name) {
		// At first, we have to go throug the whole
		// list and try to find the entry by the name
		// given as a parameter

		// To do that, we need a temporary pointer
		// pointing to a current entry
        Entry* current = firstEntry;
		// To help us maintain reconnect the pointers,
		// we will have additional pointer to remember
		// previous pointer of the current entry.
        Entry* previous = 0;

		// As long as the pointer to the current entry
		// is valid, we will continue searching
        while (current != 0) {
			// We've got to check if the name of current entry
			// is the one we are looking for.
            if (current->getName() == name) {
				// If it is, we've got to remove the current
				// entry from the list.
				// There are three cases:
				
				// 1) The current entry is not the first one,
				//    neighter the last one.
				if (current != firstEntry && current != lastEntry)
					// In this case, we only chage the next entry
					// of the previus one.
                    previous->next = current->next;

				// 2) The current entry is the first one.
                if (current == firstEntry)
					// Since we are about to delete the first entry,
					// we've got to change the pointer to the first entry,
					// because it will no longer be the same.
                    firstEntry = current->next;
                
				// 3) The current entry is the last one.
				// !! Don't use else here,
				// because the same entry can be the first one
				// and the last one at the same time.
				if (current == lastEntry) {
					// If it's not the first one at the same time
					// (if it has some previous one),
					// we have to correct the prevoius one.
                    if(previous != 0)
                        previous->next= 0;
					// In any case, the previous entry becoms the last one,
					// even if it does not exist.
					// (In such case the last one also should not exist.)
                    lastEntry = previous;
				}

				// Finally, no matter which case it was,
				// we have to free the memory,
				// because the removed entry will no longer be used.
                delete current;

				// If we return here, we will not remove following entries
				// with the same name.
				// What do we have to change to let us remove all of them?
				// Try it...
				return;
            }
            previous = current;
            current = current->next;
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

