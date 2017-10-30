#ifndef CONTROL_H
#define CONTROL_H

#include <Windows.h>
#include <iostream>
#include "Car.h"
#include "Draw.h"

class Control
{
public:
	Control();
	~Control();

	void carControl(Car* car);
	bool pause(Draw* draw);
	void exitGame();
};

#endif // CONTROL_H