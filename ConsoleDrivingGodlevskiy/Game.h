#ifndef GAME_H
#define GAME_H

#include <Windows.h>
#include <iostream>
#include <ctime>
#include "Control.h"
#include "Draw.h"
#include "MyCar.h"
#include "GameObject.h"
#include "Border.h"
#include "List.h"
#include "Wall.h"

class Game
{
public:
	Game(int maxLines);
	~Game();

	void addNewBorder(List& borderlist, int& leftX, int& rightX, int y);
	void drawCar(Draw& draw, GameObject& car, int maxLines);
	void drawInterface(Draw& draw, MyCar& car, int distance);
	void gameOver(Draw& draw, int distance);
	void startGame();

protected:
	Control control_;
	MyCar myCar_;
	Draw draw_;
	List borderlist_;
	List wallList_;
	int distance_;
	int leftX_;
	int rightX_;
	int maxLines_;
};

#endif // GAME_H

