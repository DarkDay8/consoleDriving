#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall : public GameObject
{
public:
	Wall();
	Wall(int x, int y);
	~Wall();
	bool isDead();
};

#endif // WALL_H