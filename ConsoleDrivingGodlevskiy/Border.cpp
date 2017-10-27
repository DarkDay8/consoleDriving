#include "Border.h"

Border::Border()
{
	viewHeight = 2;
	viewWidht = 1;
	view = new char *[viewWidht];
	view[0] = new char [viewHeight] {'|', '\0'};

}

Border::Border(int x, int y) : Border()
{
	this->x = x;
	this->y = y;
}

Border::~Border()
{
}

bool Border::IsDead()
{
	return false;
}
