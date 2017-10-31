#ifndef BORDER_H
#define BORDER_H

#include "GameObject.h"

class Border : public GameObject
{
public:
	Border();
	Border(int x, int y);
	virtual ~Border();
	bool isDead();
};

#endif // BORDER_H
