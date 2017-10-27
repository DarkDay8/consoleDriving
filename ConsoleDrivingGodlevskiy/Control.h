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
	//управление автомобилем
	void CarControl(Car * car);
	//установка игры на паузу
	bool Pause(Draw * draw);
	//Выход из игры
	void Exit();
};

