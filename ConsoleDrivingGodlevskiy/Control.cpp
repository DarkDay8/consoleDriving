#include "Control.h"



Control::Control()
{
}


Control::~Control()
{
}

void Control::CarControl(Car * car)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		car->SetX(car->GetX() - 1);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		car->SetX(car->GetX() + 1);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		car->SetSpeed(car->GetSpeed() + 1);
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		car->SetSpeed(car->GetSpeed() - 1);
	}
}