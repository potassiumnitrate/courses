
#include <iostream>
#include <string>
#pragma once

using namespace std;


enum COLOR { Green, Blue, White, Black, Brown };

class Animal
{
private:
	string _name;
	COLOR _color;
public:
	Animal();
	Animal(string n, COLOR c);
	~Animal();

	// getters
	string getName();
	string getStrColor(COLOR c);

	virtual void speak() const;
	// virtual void move() const { }
	// 3.2 part 4a: pure method
	//virtual void move() = 0;
};

// class Child : public Parent
class Mammal : public Animal
{
public:
	Mammal();
	Mammal(string n, COLOR c);
	~Mammal();
	virtual void speak() const;
	virtual void eat() const;
	// 3.2 part 4c: remove const
	virtual void move() const;
};
