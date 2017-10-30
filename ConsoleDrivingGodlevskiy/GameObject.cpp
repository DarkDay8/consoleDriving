#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	for (int i = 0; i < viewWidht_; i++)
	{
		delete[] view_[i];
	}
	delete[] view_;
}

void GameObject::setX(int x)
{
	x_ = x;
}

void GameObject::setY(int y)
{
	y_ = y;
}

int GameObject::getX()
{
	return x_;
}

int GameObject::getY()
{
	return y_;
}

int GameObject::getViewWidht()
{
	return viewWidht_;
}

int GameObject::getViewHeight()
{
	return viewHeight_;
}

char** GameObject::getView()
{
	return view_;
}
