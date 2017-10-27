#include "Car.h"

Car::Car()
{

}


Car::~Car()
{
}

void Car::SetSpeed(int speed)
{
	if (speed >= minSpeed && speed <= maxSpeed) this->speed = speed;
}

int Car::GetMaxSpeed()
{
	return maxSpeed;
}

int Car::GetSpeed()
{
	return speed;
}
