#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Item {
    string value;
    Item* next;
};

const int MAX_LENGTH = 20;

Item* readItems() {
    string userValue;
    Item* start = 0;
    Item* previous = 0;
    int i = 1;
    while (true) {
        cout << "Tell me the item number " << i++ << ": ";
        cin >> userValue;
        if (userValue == "end")
            break;

        Item* item = new Item;
        item->value = userValue;
        item->next = 0;

        if (start == 0)
            start = item;
        else
            previous->next = item;
        previous = item;
    }
    
    return start;
}

void printItems(Item* i) {
    int counter = 1;
    while (i != 0) {
        cout << "The value of the item number " << counter++ << " is: " << i->value << endl;
        i = i->next;
    }
}

void swapStrings(char*& a, char*& b) {
    char* tmp = a;
    a = b;
    b = tmp;
}

int compareStrings(char* a, char* b) {
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int d = a[i] - b[i];
        if (d != 0)
            return d;
        if (a[i] == '\0' || b[i] == '\0')
            return d;
    }
}

// the sorting is not yet rewrote for the linked list!
void sortItems(int l, char** a) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < l - 1; ++i) {
            if (compareStrings(a[i], a[i + 1]) > 0) {
                swapStrings(a[i], a[i + 1]);
                sorted = false;
            }
        }
    }
}

int main(int argc, char** argv) {
    Item* list = readItems();

    cout << "\nThe original array is:" << endl;
    printItems(list);

    // the sorting is not yet rewrote for the linked list!
    //sortItems(l, a);

    //cout << "\nThe sorted array is:" << endl;
    //printItems(l, a);

    while (list != 0) {
        Item* tmp = list;
        list = list->next;
        delete tmp;
    }

    return 0;
}

