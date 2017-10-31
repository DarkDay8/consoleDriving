#include "Border.h"

Border::Border()
{
	viewHeight_ = 2;
	viewWidht_ = 1;
	view_ = new char* [viewWidht_];
	view_[0] = new char [viewHeight_] {'|', '\0'};

	view2_ = new std::string[viewWidht_]{ "|" };
}

Border::Border(int x, int y) : Border()
{
	x_ = x;
	y_ = y;
}

Border::~Border()
{
}

bool Border::isDead()
{
	return false;
}
