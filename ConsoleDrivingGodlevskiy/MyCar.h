#ifndef MYCAR_H
#define MYCAR_H

#include "Car.h"

class MyCar : public Car
{
public:
	MyCar();
	virtual ~MyCar();
	bool isDead();
};

#endif // MYCAR_H
