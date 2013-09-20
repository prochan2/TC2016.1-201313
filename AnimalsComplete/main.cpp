
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

// here, we declare a new datatype called "animal"
// no memory is allocated here actually
// we just specify how does the data type "animal" look like
struct animal {
    string name;
    int legs;
    animal* next;
    animal* previous;
};

// this function reads a name and a number of legs of one animal
// and returns the values of the animal
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

// this function reads a name and a number of legs of one animal
// and returns a pointer to (address of) the new animal
// here, we use the dynamic memory allocation
animal* readAnimal() {
	// this is the first place where we actually allocate some memory
	// to store data (about an animal)
    animal* a = new animal;
    cout << "Give me the name of the animal" << endl;
	// if the user enters "stop" instead of the name of the animal,
	// we will stop
	if (a->name == "stop")
        return 0;
    cin >> a->name;
	// Notice that the name is set already and we can use the valu immediately.
    cout << "How many legs does the " << a->name << " have?" << endl;
    cin >> a->legs;
	// Don't forget to initialize the pointers next and previus!
	a->next = 0;
	a->previus = 0;
    return a;
}

// This function adds a new animal to an existing linked list of animals.
// The new animal is added at a proper position according to its number of legs.
// (An animal with the less amont of legs is listed first.)
// !!! If the animal should go to the first place, it wouldn't work. Try to fix it.
void addAnimal(animal* newAnimal, animal*& firstAnimal) { // the firstAnimal has to be a reference, because we may change the value
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
    
	// This block handles the situation, when we want to preped the new animal
	// to the beginning of the list
	if (currentAnimal == firstAnimal) {
        newAnimal->previous = 0; //1
        newAnimal->next = currentAnimal; //2
        currentAnimal->previous = newAnimal; //3
		// The new animal is the first one now!
        firstAnimal = newAnimal;
		// We are done here in this case.
		// The rest of the function puts the new animal to different places
        return;
    }

    animal* previous; // previous of the new one
    if (currentAnimal == 0)
		// if we have to put the new animal to the end of the list...
		// (if it has the currently highest number of legs)
        previous = lastAnimal;
    else
		// if we want to put the new animal somewer inside the list...
		// (not to the front, neighter to the end
        previous = currentAnimal->previous;
    
	// See the slide TC2016.1-Animals.
    newAnimal->next = previous->next; //1
	if (previous->next != 0) // if there is only one animal so far, this will avoid accessing invalid memory
		previous->next->previous=newAnimal; //2
    previous->next = newAnimal; //3
    newAnimal->previous = previous; //4

}

// This function finds an animal in the list
// and changes its number of legs
void changeLegs(animal*first, int newLegs, string animalName) {
	// To find the item in the list, we've got to go through the list
	// and compare the given name with the name of each animal
    animal*current = first;
    while (current != 0) {
        if (animalName == current->name) {
			// If the names match, we have found the right animal,
			// so we can do the change
            current->legs = newLegs;
			// That's all what we wated to do.
            break;
        }
        current = current->next;
    }
}

// This function prints out the whole list.
void printAnimals(animal* first){
    animal* current = first;
    while(current != 0){
        cout << current->name << " " << current->legs << endl;
        current = current->next;
    }   
}

int main(int argc, char** argv) {
	animal* a;
    animal* firstAnimal = 0;

    while(true) {
        a = readAnimal();
        if (a == 0)
            break;
        if (firstAnimal != 0) {
            addAnimal(a, firstAnimal);
        } else {
            firstAnimal = a;
        }
    }
    
    cout<<"The list:"<<endl;
    printAnimals(firstAnimal);

    changeLegs(firstAnimal, 3, "bird");
    
    cout<<"The with weird bird:"<<endl;
    printAnimals(firstAnimal);

	// here we have to free the allocated memory!!!
	animal* current = firstAnimal;
	animal* next;
	while (current != 0) {
		next = current->next;
		delete current;
		current = next;
	}

    return 0;
}
