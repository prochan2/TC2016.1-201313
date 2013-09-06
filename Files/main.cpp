#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    // You've got to put here a path to an existing text file
    // Working with text files:
    // - on Windows use Notepad
    // - on OSX (Mac) use TextEdit and use menu Format > Make Plain Text (not RTF)
    // - on Linux use gedit (on Gnome) or kedit (on KDE)
    file.open("/Users/alumno/NetBeansProjects/files/textfile.txt");
    
    string line;
    while (file.good()) {
        file >> line;
        cout << line << " ";
    }
    
    // Don't forget to close the file in the end!
    file.close();
    return 0;
}

