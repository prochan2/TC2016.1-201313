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

void swapStrings(string& a, string& b) {
    string tmp = a;
    a = b;
    b = tmp;
}

void sortItems(Item* list) {
    bool sorted = false;
    Item* i;
    while (!sorted) {
        sorted = true;
        i = list;
        while (i->next != 0) {
            if (i->value > i->next->value) {
                swapStrings(i->value, i->next->value);
                sorted = false;
            }
            
            i = i->next;
        }
    }
}

int main(int argc, char** argv) {
    Item* list = readItems();

    cout << "\nThe original list is:" << endl;
    printItems(list);

    sortItems(list);

    cout << "\nThe sorted list is:" << endl;
    printItems(list);

    while (list != 0) {
        Item* tmp = list;
        list = list->next;
        delete tmp;
    }

    return 0;
}

