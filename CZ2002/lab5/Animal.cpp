
#include "Animal.h"
#include "childAnimal.h"
#include <iostream>
#include <string>

using namespace std;

Animal::Animal() : _name("unknown") {
	cout << "constructing Animal object " << _name << endl;
}
Animal::Animal(string n, COLOR c) : _name(n), _color(c) {
	cout << "constructing " << getStrColor(c) << " Animal " << _name << endl;
}
Animal::~Animal() {
	cout << "destructing Animal object " << _name << endl;
}
// getters
string Animal::getName() {
	return _name;
}
string Animal::getStrColor(COLOR c) {
	string str_color;
	switch (c) {
	case Green:
		str_color = "Green";
		break;
	case Blue:
		str_color = "Blue";
		break;
	case White:
		str_color = "White";
		break;
	case Black:
		str_color = "Black";
		break;
	case Brown:
		str_color = "Brown";
		break;
	}
	return str_color;
}
void Animal::speak() const {
	cout << "Animal speaks " << endl;
}
// virtual void move() const { }
// 3.2 part 4a: pure method
// void Animal::move() = 0;


// class Child : public Parent
Mammal::Mammal() : Animal() {
	cout << "constructing Mammal object " << Animal::getName() << endl;
}
Mammal::Mammal(string n, COLOR c) : Animal(n, c) {
	cout << "constructing " << Animal::getStrColor(c) << " Mammal " << Animal::getName() << endl;
}
Mammal::~Mammal() {
	cout << "destructing Mammal object " << Animal::getName() << endl;
}
void Mammal::speak() const {
	cout << "Mammal speaks " << endl;
}
void Mammal::eat() const {
	cout << "Mammal eat " << endl;
}
// 3.2 part 4c: remove const
void Mammal::move() const {
	cout << "Mammal move " << endl;
}


Dog::Dog() : Mammal(), _owner("unknown") {
	cout << "constructing Dog object " << Animal::getName() << endl;
}
Dog::Dog(string n, COLOR c, string o) : Mammal(n, c) {
	_owner = o;
	cout << "constructing " << Animal::getStrColor(c) << " Dog " << Animal::getName() << endl;
}
Dog::~Dog() {
	cout << "destructing Dog object " << Animal::getName() << endl;
}
void Dog::speak() const {
	cout << "Woof" << endl;
}
// 3.2 part 4c
void Dog::move() const {
	cout << "Dog move " << endl;
}
void Dog::eat() const {
	cout << "Dog eat " << endl;
}


// 3.3 part 4
Cat::Cat() : Mammal(), _owner("unknown") {
	cout << "constructing Cat object " << Animal::getName() << endl;
}
Cat::Cat(string n, COLOR c, string o) : Mammal(n, c) {
	_owner = o;
	cout << "constructing " << Animal::getStrColor(c) << " Cat " << Animal::getName() << endl;
}
Cat::~Cat() {
	cout << "destructing Cat object " << Animal::getName() << endl;
}
void Cat::speak() const {
	cout << "Cat meow" << endl;
}
void Cat::move() const {
	cout << "Cat move " << endl;
}
void Cat::eat() const {
	cout << "Cat eat " << endl;
}


// 3.3 part 4
Lion::Lion() : Mammal() {
	cout << "constructing Lion object " << Animal::getName() << endl;
}
Lion::Lion(string n, COLOR c) : Mammal(n, c) {
	cout << "constructing " << Animal::getStrColor(c) << " Lion " << Animal::getName() << endl;
}
Lion::~Lion() {
	cout << "destructing Lion object " << Animal::getName() << endl;
}

void Lion::speak() const {
	cout << "Lion roar" << endl;
}

void Lion::move() const {
	cout << "Lion move " << endl;
}
void Lion::eat() const {
	cout << "Lion eat " << endl;
}

/*
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
/*
	int choice = 0;
	Mammal **mammal = new Mammal*[3];
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
	/*for (int i = 0; i < 3; i++) {
		delete mammal[i];
	}
	delete [] mammal;
	*/
	/*
		cout << "Program exiting ..." << endl;
		return 0;
	};
	*/


