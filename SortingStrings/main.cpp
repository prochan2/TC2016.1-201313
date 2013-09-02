#include <cstdlib>
#include <iostream>

using namespace std;

const int MAX_LENGTH = 20;

int readLength() {
    cout << "What will be the length of the array?" << endl;
    int l;
    cin >> l;
    return l;
}

void readItems(int l, char** a) {
    for (int i = 0; i < l; ++i) {
        cout << "Tell me the item number " << (i + 1) << ": ";
        cin >> a[i];
    }
}

void printItems(int l, char** a) {
    for (int i = 0; i < l; ++i)
        cout << "The value of the item number " << (i + 1) << " is: " << a[i] << endl;
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

void sortItems(int l, char** a) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < l - 1; ++i) {
            if (compareStrings(a[i], a[i+1]) > 0) {
                swapStrings(a[i], a[i + 1]);
                sorted = false;
            }
        }
    }
}

int main(int argc, char** argv) {
    int l = readLength();
    cout << "The length of the array will be " << l << "." << endl;

    char** a = new char*[l];
    for (int i = 0; i < l; ++i)
        a[i] = new char[MAX_LENGTH];

    readItems(l, a);

    cout << "\nThe original array is:" << endl;
    printItems(l, a);
    
    sortItems(l, a);
    
    cout << "\nThe sorted array is:" << endl;
    printItems(l, a);

    for (int i = 0; i < l; ++i)
        delete [] a[i];
    delete [] a;

    return 0;
}

