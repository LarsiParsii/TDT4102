#include "car.h"

Car::Car(int freeSeats)
{
	freeSeats = freeSeats;
}

bool Car::hasFreeSeats() const
{
	return freeSeats > 0;
}

void Car::reserveFreeSeat()
{
	freeSeats--;
}
