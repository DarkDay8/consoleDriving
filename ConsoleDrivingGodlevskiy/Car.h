#ifndef CAR_H
#define CAR_H

#include "GameObject.h"

class Car: public GameObject
{

public:
	Car();
	~Car();
	void setSpeed(int speed);
	int getMaxSpeed();
	int getSpeed();
	virtual bool isDead() = 0;

protected:
	int speed_;
	int maxSpeed_;
	int minSpeed_;
};

#endif // CAR_H
