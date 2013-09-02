#include <cstdlib>
#include <iostream>

using namespace std;

int readLength() {
    cout << "What will be the length of the array?" << endl;
    int l;
    cin >> l;
    return l;
}

void readItems(int l, int* a) {
    for (int i = 0; i < l; ++i) {
        cout << "Tell me the item number " << (i + 1) << ": ";
        cin >> a[i];
    }
}

void printItems(int l, int* a) {
    for (int i = 0; i < l; ++i)
        cout << "The value of the item number " << (i + 1) << " is: " << a[i] << endl;
}

void swapNumbers(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void sortItems(int l, int *a) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < l - 1; ++i) {
            if (a[i] > a[i + 1]) {
                swapNumbers(a[i], a[i + 1]);
                sorted = false;
            }
        }
    }
}

int main(int argc, char** argv) {
    int l = readLength();
    cout << "The length of the array will be " << l << "." << endl;

    int* a = new int[l];

    readItems(l, a);

    cout << "\nThe original array is:" << endl;
    printItems(l, a);
    
    sortItems(l, a);
    
    cout << "\nThe sorted array is:" << endl;
    printItems(l, a);

    delete [] a;

    return 0;
}

