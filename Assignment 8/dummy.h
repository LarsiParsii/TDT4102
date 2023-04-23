#pragma once
#include <iostream>
#include <utility>

// Prototypes
void dummyTest();

class Dummy
{
public:
	int *num;
	Dummy()
	{
		num = new int{0};
	}
	~Dummy()
	{
		delete num;
	}
	Dummy(const Dummy &other) {
		this->num = new int{};
		*num = *other.num;
	}
	Dummy &operator=(Dummy rhs)
	{
		*num = *rhs.num;
		return *this;
	}
};