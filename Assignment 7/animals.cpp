#include "std_lib_facilities.h"
#include "animals.h"

void testAnimal(void)
{
	/*
	Animal dyr("Et dyrenavn", 69);
	Cat lillepus("Lillepus", 14);
	Dog fly("Fly", 15);
	
	cout << dyr.toString() << endl;
	cout << lillepus.toString() << endl;
	cout << fly.toString() << endl;
	*/
	
	vector<unique_ptr<Animal>> animalVector;
	
	// animalVector.emplace_back(new Animal("Et dyrenavn", 69));
	animalVector.emplace_back(new Cat("Lillepus", 14));
	animalVector.emplace_back(new Dog("Fly", 15));
	
	for (unsigned i = 0; i < 2; i++)
	{
		cout << animalVector.at(i)->toString() << endl;
	}
}

Animal::Animal(string n, int a)
{
	name = n;
	age = a;
}

/*
string Animal::toString()
{
	string output;
	output = "Animal: " + Animal::name + ", " + to_string(Animal::age);
	return output;
}
*/

Cat::Cat(string n, int a) : Animal(n, a) {};

string Cat::toString()
{
	string output;
	output = "Cat: " + Animal::name + ", " + to_string(Animal::age);
	return output;
}

Dog::Dog(string n, int a) : Animal(n, a) {};

string Dog::toString()
{
	string output;
	output = "Dog: " + Animal::name + ", " + to_string(Animal::age);
	return output;
}
