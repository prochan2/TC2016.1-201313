#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Structure containing value(s) of one item of the Linked List
// and a pointer to the next item.
// If it is the last item, the pointer has to be set to 0.
// This is a Single Linked List. Double Linked List has also pointer to the previous item.
struct Item {
    string value;
    Item* next;
};

// This function reads all items into a new Linked List and return a pointer to the first item of the list.
Item* readItems() {
    string userValue;
    Item* start = 0;
    Item* previous = 0;
    int i = 1;

    // This is called "infinite loop". In fact, it is not infinite - we interrupt it using the keyword break.
    while (true) {
        cout << "Tell me the item number " << i++ << ": ";
        cin >> userValue;
	// User has to enter text "end" to stop creating the list.
        if (userValue == "end")
            break;

	// Here we create new item of the list.
        Item* item = new Item;
	// Here we assign the value of the item.
        item->value = userValue;
	// So far, this is the last item, so we initialize the pointer to the next item to 0.
        item->next = 0;

        if (start == 0)
  	    // If this is the first item read so far, we will save a pointer to this item to be able to return it by this function.
            start = item;
        else
	    // If it is not the first one, we append it to the previous item read.
            previous->next = item;

	// We change here the pointer to the "previous" item for the next iteration.
        previous = item;
    }
    
    return start;
}

void printItems(Item* i) {
    // We use the counter here just to let the user know which item is being displayed.
    int counter = 1;
    // Notice that the i here is a pointer to an Item - not an index as it used to be for arrays.
    // Since the last item has the pointer set to 0, we can use this feature to notice the and of the list.
    while (i != 0) {
	// Notice the difference between counter++ and ++counter. What would happed if we chage it here to ++counter?
        cout << "The value of the item number " << counter++ << " is: " << i->value << endl;
	// To continue to the next item, we change the pointer i.
	// Notice that we use the variable i given as a parameter. We cad do this, because we do not change the original variable, since we've got only it's value, not the variable itself (see swapStrings).
        i = i->next;
    }
}

// Here we use the references, so we change the original values passed by calling this function.
void swapStrings(string& a, string& b) {
    string tmp = a;
    a = b;
    b = tmp;
}

// This is the same bubble sort algorithm as for arrays, just the iteration through the Linked List is different from the iteration though arrays.
// (see printItems)
void sortItems(Item* list) {
    bool sorted = false;
    Item* i;
    while (!sorted) {
        sorted = true;
        i = list;
	// Notice this condition. If we have i != 0 here, we would try to read an item behind the end of the list
        while (i->next != 0) {
	    // here
            if (i->value > i->next->value) {
		// and here
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

    // This is how to correctly free the memory allocated for the Linked List.
    // Notice that we can change the pointe list, since we would't use it anymore after the deletition of the Linked List.
    // (We cannot since the Linked List will be deleted.)
    while (list != 0) {
        Item* tmp = list;
        list = list->next;
        delete tmp;
    }

    return 0;
}

