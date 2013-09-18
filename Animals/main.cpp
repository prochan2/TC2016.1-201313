
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

// here, we define a new datatype
// no memory is allocated here actually
// we just specify, how does the data type "animal" look like
struct animal {
    string name;
    int legs;
    animal* next;
    animal* previous;
};

// this method reads a name and a number of legs of one animal
// here, we use the static memory allocation
// we've left here this code to let you see the difference between static and dynamic usage of memory
/*animal readAnimal(){
    animal a;
    cout<<"Give me the name of the animal" <<endl;
    cin>> a.name ;
    cout<<"How many legs does the " << a.name << " have?" <<endl;
    cin>> a.legs;
    return a;
}*/

// this method reads a name and a number of legs of one animal
// here, we use the dynamic memory allocation
animal* readAnimal() {
    animal*a = new animal;
    cout << "Give me the name of the animal" << endl;
    cin >> a->name;
	// Notice that the name is set already and we can use the valu immediately.
    cout << "How many legs does the " << a->name << " have?" << endl;
    cin >> a->legs;
    return a;
}

// This function adds a new animal to an existing linked list of animals.
// The new animal is added at a proper position according to its number of legs.
// (An animal with the less amont of legs is listed first.)
// !!! If the animal should go to the first place, it wouldn't work. Fix it.
void addAnimal(animal* newAnimal, animal* firstAnimal) {
    animal* currentAnimal = firstAnimal;
    animal* lastAnimal=0;
    while (currentAnimal != 0) {
        if (newAnimal->legs < currentAnimal->legs) {
            break;
        }
		// Notice, that in case we want only one statement to be performed in some condition,
		// we can ommit the curly baces of the if clause.
        if (currentAnimal->next == 0)
            lastAnimal = currentAnimal;
		// So this statement does not belong to the if. Only the previous one.
        currentAnimal = currentAnimal->next;
		// "currentAnimal->next" means only "i want to work with the varable next
		// inside the variable currentAnimal". Nothing else.
		// I does not perform any action.
    } // end of while
    
    animal* previous; // previous of the new one
    if (currentAnimal == 0)
        previous = lastAnimal;
    else
        previous = currentAnimal->previous;
    
	// See the slide TC2016.1-Animals.
    newAnimal->next = previous->next; //1
    previous->next->previous=newAnimal; //2
    previous->next = newAnimal; //3
    newAnimal->previous = previous; //4

}

int main(int argc, char** argv) {

	// !!! Try to use these functions and output the list in the end.

	// !!! Don't forget to delete all dynamically allocated memory in the end!

    return 0;
}
