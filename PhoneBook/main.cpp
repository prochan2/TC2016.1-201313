#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int ask_option() {
    cout << endl;
    cout << "P H O N E   B O O K" << endl;
    cout << "1) Print book" << endl;
    cout << "2) Find person" << endl;
    cout << "3) Add person" << endl;
    cout << "4) Remove person" << endl;
    cout << "5) Change name" << endl;
    cout << "6) Change number" << endl;
    cout << "0) End" << endl;

    int users_option;
    cin >> users_option;

    cout << endl;

    return users_option;
}

void announce_wrong_option() {
    cout << "Wrong option!" << endl;
}

void initialize_names(string* names, int count) {
    for (int i = 0; i < count; ++i)
        names[i] = "";
}

void print_book(string* names, int* numbers, int count) {
    for (int i = 0; i < count; ++i)
        if (names[i] == "")
            cout << "--" << endl;
        else
            cout << names[i] << ": " << numbers[i] << endl;
}

int main(int argc, char** argv) {
    int count = 5;
    string* names = new string[count];
    int* numbers = new int[count];

    initialize_names(names, count);
    
    int users_option;
    do {
        users_option = ask_option();
        switch (users_option) {
            case 1: //Print book
                print_book(names, numbers, count);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                break;
            default:
                announce_wrong_option();
                break;
        };
    } while (users_option != 0);

    return 0;
}

