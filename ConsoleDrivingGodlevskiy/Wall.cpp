#include "Wall.h"

Wall::Wall()
{
	viewHeight_ = 6;
	viewWidht_ = 3;
	view_ = new char *[viewWidht_];
	view_[0] = new char [viewHeight_] {'/', '-', '-', '-', '\\', '\0'};
	view_[1] = new char [viewHeight_] {'|', ' ', ' ', ' ', '|', '\0'};
	view_[2] = new char [viewHeight_] {'\\', '-', '-', '-', '/', '\0'};

	view2_ = new std::string[viewWidht_]{ "/---\\", "|   |","\\---/" };
}

Wall::Wall(int x, int y) : Wall()
{
	x_ = x;
	y_ = y;
}

Wall::~Wall()
{

}

bool Wall::isDead()
{
	return false;
}