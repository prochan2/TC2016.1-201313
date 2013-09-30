#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// this function generates a random number
// between min and max
int rand(int min, int max) {
    srand(time(0));
    return rand() % (max - min + 1) + min;
}

int main(int argc, char** argv) {
    int min = 1;
    int max = 100;

    // Here we generate the computers number
    int computersNumber = rand(min, max);

    // You can uncomment the following line to see
    // what number should be guessed. (Or to cheat :) )
    //cout << computersNumber << endl;
    
    int playersNumber;

    // Because we want to ask the player for at least one number,
    // we use the do-while cycle.
    do {
	// Here we are continuously asking the player for his guess
        cout << "Guess a number between " << min << " and " << max << ":" << endl;
        cin >> playersNumber;

	// If the tip is incorrect, we give a hint.
        if (playersNumber < computersNumber)
            cout << "That's too little! :(" << endl;
        else if (playersNumber > computersNumber)
            cout << "That's too big! :(" << endl;

	// if the tip is incorrect, we continue asking.
    } while (playersNumber != computersNumber);

    // This code is reached only in case the tip was correct,
    // so we don't need any other if-clause here.
    cout << "That's it! :)" << endl;

    return 0;
}

