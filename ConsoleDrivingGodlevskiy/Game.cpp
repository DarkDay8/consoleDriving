#include "Game.h"

Game::Game(int maxLines) : maxLines_(maxLines)
{
	for (int i = maxLines - 1; i >= 0; i--)
	{
		addNewBorder(borderlist_, leftX_, rightX_, i);
	}
}


Game::~Game()
{
	borderlist_.delAll();
	wallList_.delAll();
}

void Game::addNewBorder(List& borderlist, int& leftX, int& rightX, int y)
{
	const int ROAD_HEIGHT = 50;
	const int BASIC_ROAD_DEVIATION = 2;
	const int MIN_DEVIATION = 0;
	const int MAX_DEVIATION = 10;

	if (rand() % 10 > 6 && leftX < MAX_DEVIATION)
		leftX++;
	else if (rand() % 10 > 6 && leftX > MIN_DEVIATION)
		leftX--;
	
	if (rand() % 10 > 6 && rightX < MAX_DEVIATION)
		rightX++;
	else if (rand() % 10 > 6 && rightX > MIN_DEVIATION)
		rightX--;

	borderlist.addHead(new Border(BASIC_ROAD_DEVIATION + leftX, y));
	borderlist.addHead(new Border(BASIC_ROAD_DEVIATION + ROAD_HEIGHT + rightX, y));
}

void Game::drawCar(Draw& draw, GameObject& car, int maxLines)
{
	draw.setColor(Red, Black);
	draw.drawGameObject(&car, maxLines);
	draw.setColor(White, Black);
}

void Game::drawInterface(Draw& draw, MyCar& car, int distance)
{
	draw.setColor(LightCyan, Black);
	draw.gotoXY(55, 5);
	printf("Speed: %d ", 10 + car.getSpeed() * 10);
	draw.gotoXY(55, 7);
	printf("Distance: %d ", distance);
	draw.setColor(White, Black);
}

void Game::gameOver(Draw& draw, int distance)
{
	int sleeptime = 500;

	system("cls");
	draw.setColor(Yellow, Black);
	draw.gotoXY(31, 17);
	printf("GAME OVER");
	draw.gotoXY(23, 20);
	printf("You drove %d kilometers", distance);
	Sleep(sleeptime);
	exit(0);
}

void Game::borderManagement(GameObject* border)
{
	bool topLeft = myCar_.getX() <= border->getX();
	bool topRight = myCar_.getX() + myCar_.getViewHeight() - 2 >= border->getX();
	bool bottonLeft = myCar_.getY() <= border->getY();
	bool bottonRigth = myCar_.getY() + myCar_.getViewWidht() - 1 >= border->getY();

	if (topLeft && topRight && bottonLeft && bottonRigth)
		gameOver(draw_, distance_);

	draw_.drawGameObject(border, maxLines_);
	border->setY(border->getY() + 1);
}

void Game::wallManagement(GameObject* wall, int currentIndex)
{
	bool topLeft = myCar_.getX() <= wall->getX() + wall->getViewHeight() - 2;
	bool topRight = myCar_.getX() + myCar_.getViewHeight() - 2 >= wall->getX();
	bool bottonLeft = myCar_.getY() <= wall->getY() + wall->getViewWidht() - 1;
	bool bottonRigth = myCar_.getY() + myCar_.getViewWidht() - 1 >= wall->getY();

	if (topLeft && topRight && bottonLeft && bottonRigth)
		gameOver(draw_, distance_);

	wall->setY(wall->getY() + 1);

	if (wall->getY() > maxLines_)
		wallList_.del(currentIndex);

	draw_.drawGameObject(wall, maxLines_);
}


void Game::startGame()
{
	draw_.showCursor(false);

	for (int i = maxLines_ - 1; i >= 0; i--)
		addNewBorder(borderlist_, leftX_, rightX_, i);

	while (true)
	{
		while (!control_.pause(&draw_))
		{
			control_.exitGame();
			system("cls");

			for (int i = 0; i < maxLines_ * 2; i++)
				borderManagement(borderlist_.getElem(i)->data);

			borderlist_.delTail();
			borderlist_.delTail();

			draw_.setColor(Yellow, Black);

			for (int i = 0; i < wallList_.getCount(); i++)
				wallManagement(wallList_.getElem(i)->data, i);

			draw_.setColor(White, Black);
			drawCar(draw_, myCar_, maxLines_);
			drawInterface(draw_, myCar_, distance_);

			addNewBorder(borderlist_, leftX_, rightX_, 0);

			if (rand() % 100 < 15)
				wallList_.addHead(new Wall(rand() % 45 + 10, -3));

			control_.carControl(&myCar_);
			Sleep(500 - 30 * myCar_.getSpeed());
			distance_++;
		}

		control_.exitGame();
		Sleep(500);
	}
}
