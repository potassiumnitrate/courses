
#include "Animal.h"
#include "childAnimal.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	/* 3.2 part 4c: comment out Animal object
	   bc move is pure virtual function
	Animal a("Cat", Black);
	a.speak();
	*/

	// 3.2
	/*
	Mammal b("Whale", Blue);
	b.speak();
	Dog c("Doggy", Brown, "Berlynn");
	c.speak();
	cout << "Program exiting ..." << endl ;
	return 0;
	*/

	// 3.3 part 1
	/*
	Animal* animalPtr = new Dog("Lassie", White, "Andy");
	animalPtr->speak();
	animalPtr->move();
	delete animalPtr;
	*/

	//3.3 part 3
	/*
	Dog dogi("Lassie", White, "Andy");
	Mammal *aniPtr = &dogi;	// Animal obj
	Mammal &aniRef = dogi;	// Mammal obj
	Mammal aniVal = dogi;	// Dog obj
	aniPtr->speak();	// Woof
	aniRef.speak();		// Woof
	aniVal.speak();		// Mammal::speak()
	*/

	// 3.3 part 4

	int choice = 0;
	Mammal** mammal = new Mammal * [3];
	mammal[0] = new Dog();
	mammal[1] = new Cat();
	mammal[2] = new Lion();

	do {
		cout << "Select the animal to send to Zoo:" << endl;
		cout << "(1) Dog  (2) Cat  (3) Lion  (4) Move all animals  (5) Quit" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			mammal[0]->move();
			mammal[0]->speak();
			mammal[0]->eat();
			break;
		case 2:
			mammal[1]->move();
			mammal[1]->speak();
			mammal[1]->eat();
			break;
		case 3:
			mammal[2]->move();
			mammal[2]->speak();
			mammal[2]->eat();
			break;
		case 4:
			for (int i = 0; i < 3; i++) {
				mammal[i]->move();
				mammal[i]->speak();
				mammal[i]->eat();
			}
			break;
		}
	} while (choice != 5);

	// delete pointers
	for (int i = 0; i < 3; i++) {
		delete mammal[i];
	}
	delete[] mammal;

	cout << "Program exiting ..." << endl;
	return 0;
};





