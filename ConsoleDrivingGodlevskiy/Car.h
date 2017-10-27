#pragma once
#include "GameObject.h"

class Car: public GameObject
{
protected:
	int speed;
	int maxSpeed;
	int minSpeed;
public:
	Car();
	~Car();
	void SetSpeed(int speed);
	int GetMaxSpeed();
	int GetSpeed();

	virtual bool IsDead() = 0;

};

