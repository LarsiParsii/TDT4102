#pragma once
#include "std_lib_facilities.h"

void testAnimal(void);

class Animal
{
public:
	Animal(string n, int a);
	virtual ~Animal(){};
	virtual string toString() = 0;
protected:
	string name;
	int age;
};

class Cat : public Animal
{
public:
	Cat(string n, int a);
	string toString() override;
};

class Dog : public Animal
{
public:
	Dog(string n, int a);
	string toString() override;
};