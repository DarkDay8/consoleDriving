#pragma once
#include "Car.h"
#include "Draw.h"
#include <Windows.h>
#include <iostream>

class Control
{
public:
	Control();
	~Control();
	void CarControl(Car * car);
	bool Pause(Draw * draw);
	void Exit();
};

