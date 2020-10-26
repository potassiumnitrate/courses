#include <iostream>
#include <string>
#include "Animal.h"
#pragma once

using namespace std;

class Dog : public Mammal
{
private:
	string _owner;
public:
	Dog();
	Dog(string n, COLOR c, string o);
	~Dog();
	void speak() const;
	// 3.2 part 4c
	void move() const;
	void eat() const;
};

// 3.3 part 4
class Cat : public Mammal
{
private:
	string _owner;
public:
	Cat();
	Cat(string n, COLOR c, string o);
	~Cat();
	void speak() const;
	void move() const;
	void eat() const;
};

// 3.3 part 4
class Lion : public Mammal
{
private:
	string _owner;
public:
	Lion();
	Lion(string n, COLOR c);
	~Lion();
	void speak() const;
	void move() const;
	void eat() const;
};
