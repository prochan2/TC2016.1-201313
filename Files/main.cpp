#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    // You've got to put here a path to an existing text file
    // Working with text files:
    // - on Windows use Notepad, backslashes in the path have to be doubled! (\\)
    // - on OSX (Mac) use TextEdit and use menu Format > Make Plain Text (not RTF)
    // - on Linux use gedit (on Gnome) or kedit (on KDE)
    file.open("/Users/alumno/NetBeansProjects/files/textfile.txt");
    
    // This way you can read the file word by word.
    // To see how to process the file by lines, have a look at slides TC2016.1-Lesson9-C++practice
    string word;
    while (file.good()) {
        file >> word;
        cout << word << " ";
    }
    
    // Don't forget to close the file in the end!
    file.close();
    return 0;
}

