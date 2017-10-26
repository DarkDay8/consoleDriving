#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::SetX(int x)
{
	this->x = x;
}

void GameObject::SetY(int y)
{
	this->y = y;
}


int GameObject::GetX()
{
	return x;
}

int GameObject::GetY()
{
	return y;
}

int GameObject::GetViewWidht()
{
	return viewWidht;
}

int GameObject::GetViewHeight()
{
	return viewHeight;
}

char ** GameObject::GetView()
{
	return view;
}
