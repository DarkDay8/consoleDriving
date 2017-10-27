#include "Wall.h"



Wall::Wall()
{
	viewHeight = 5;
	viewWidht = 3;
	view = new char *[viewWidht];
	view[0] = new char [viewHeight] {'/', '-', '-', '-', '\\', '\0'};
	view[1] = new char [viewHeight] {'|', ' ', ' ', ' ', '|', '\0'};
	view[2] = new char [viewHeight] {'\\', '-', '-', '-', '/', '\0'};
}

Wall::Wall(int x, int y)
{
	this->x = x;
	this->y = y;
}


Wall::~Wall()
{
}

bool Wall::IsDead()
{
	return false;
}