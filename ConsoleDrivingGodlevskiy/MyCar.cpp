#include "MyCar.h"

MyCar::MyCar()
{
	x = 20;
	y = 23;
	viewHeight = 5;
	viewWidht = 4;
	maxSpeed = 15;
	minSpeed = 0;
	view = new char *[viewWidht];
	view[0] = new char [viewHeight] {'/', '=', '=', '\\', '\0' };
	view[1] = new char [viewHeight] { '0', ' ', ' ', '0', '\0' };
	view[2] = new char [viewHeight] { '[', '[', ']', ']', '\0' };
	view[3] = new char [viewHeight] { '0', '/', '\\', '0', '\0' };

}

MyCar::~MyCar()
{
}

bool MyCar::IsDead()
{
	return false;
}
