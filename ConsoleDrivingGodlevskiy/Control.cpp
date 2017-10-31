#include "Control.h"


Control::Control()
{
}

Control::~Control()
{
}

void Control::carControl(Car* car)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		car->setX(car->getX() - 1);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		car->setX(car->getX() + 1);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		car->setSpeed(car->getSpeed() + 1);
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		car->setSpeed(car->getSpeed() - 1);
	}
}

bool Control::pause(Draw* draw)
{
		if (GetKeyState(VK_RETURN))
		{
			draw->writeStr(25, 28, "PAUSE!!!");
			return true;			
		}	
}

void Control::exitGame()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		exit(0);
	}
}
