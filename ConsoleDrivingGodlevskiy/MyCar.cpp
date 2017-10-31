#include "MyCar.h"

MyCar::MyCar()
{
	x_ = 20;
	y_ = 23;
	viewHeight_ = 5;
	viewWidht_ = 4;
	maxSpeed_ = 15;
	minSpeed_ = 0;
	view_ = new char *[viewWidht_];
	view_[0] = new char [viewHeight_] {'/', '=', '=', '\\', '\0' };
	view_[1] = new char [viewHeight_] { '0', ' ', ' ', '0', '\0' };
	view_[2] = new char [viewHeight_] { '[', '[', ']', ']', '\0' };
	view_[3] = new char [viewHeight_] { '0', '/', '\\', '0', '\0' };

	view2_ = new std::string[viewWidht_]{ "/==\\", "0  0","[[]]", "0/\\0" };
}

MyCar::~MyCar()
{
}

bool MyCar::isDead()
{
	return false;
}
