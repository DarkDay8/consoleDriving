#include "Car.h"

Car::Car()
{
}


Car::~Car()
{
}

void Car::setSpeed(int speed)
{
	if (speed >= minSpeed_ && speed <= maxSpeed_) speed_ = speed;
}

int Car::getMaxSpeed()
{
	return maxSpeed_;
}

int Car::getSpeed()
{
	return speed_;
}
