#include <cstdlib>
#include <iostream>

using namespace std;

int readLength() {
    int length;
    cout << "Give me a count of your numbers: " << endl;
    cin >> length;
    return length;
}

void readNumbers(int* array, int length) {
    cout << "Give me " << length << " numbers." << endl;
    for (int i = 0; i < length; ++i)
        cin >> array[i];
}

void printNumbers(int* array, int length, char* array_name) {
    cout << "The numbers in the " << array_name << " array are: ";
    for (int i = 0; i < length; ++i) {
        cout << array[i];
        // This is to avoid the last colon
        if (i < (length - 1))
            cout << ", ";
    }
    cout << endl;
}

// Try to define the sortNumbers function.
// Also try the same with strings. (Sorting strings.)
int main(int argc, char** argv) {
    int length = readLength();

    int *array = new int[length];
    
    readNumbers(array, length);
   
    printNumbers(array, length, "original");
    
    // Try to define this one
    // You can comment out this line to test the program without sorting.
    sortNumbers(array, length);
    
    printNumbers(array, length, "sorted");
    
    delete [] array;
    
    return 0;
}

