#pragma once
#include "GameObject.h"
class Border : public GameObject
{
public:
	Border();
	Border(int x, int y);
	~Border();
	bool IsDead();
};

