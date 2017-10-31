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
	if (rand() % 10 > 6 && leftX < 10) 
		leftX++;
	else if (rand() % 10 > 6 && leftX > 0)
		leftX--;
	borderlist.addHead(new Border(2 + leftX, y));
	if (rand() % 10 > 6 && rightX < 10) 
		rightX++;
	else if (rand() % 10 > 6 && rightX > 0) 
		rightX--;
	borderlist.addHead(new Border(50 + rightX, y));
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
	system("cls");
	draw.setColor(Yellow, Black);
	draw.gotoXY(31, 17);
	printf("GAME OVER");
	draw.gotoXY(23, 20);
	printf("You drove %d kilometers", distance);
	Sleep(5000);
	exit(0);
}

void Game::borderManagement(GameObject* border)
{
	bool topLeft, topRight, bottonLeft, bottonRigth;

	topLeft = myCar_.getX() <= border->getX();
	topRight = myCar_.getX() + myCar_.getViewHeight() - 2 >= border->getX();
	bottonLeft = myCar_.getY() <= border->getY();
	bottonRigth = myCar_.getY() + myCar_.getViewWidht() - 1 >= border->getY();

	if (topLeft && topRight && bottonLeft && bottonRigth)
		gameOver(draw_, distance_);

	draw_.drawGameObject(border, maxLines_);
	border->setY(border->getY() + 1);
}

void Game::wallManagement(GameObject* wall, int currentIndex)
{
	bool topLeft, topRight, bottonLeft, bottonRigth;

	topLeft = myCar_.getX() <= wall->getX() + wall->getViewHeight() - 2;
	topRight = myCar_.getX() + myCar_.getViewHeight() - 2 >= wall->getX();
	bottonLeft = myCar_.getY() <= wall->getY() + wall->getViewWidht() - 1;
	bottonRigth = myCar_.getY() + myCar_.getViewWidht() - 1 >= wall->getY();

	if (topLeft && topRight && bottonLeft && bottonRigth)
		gameOver(draw_, distance_);

	wall->setY(wall->getY() + 1);

	if (wall->getY() > maxLines_)
		wallList_.del(currentIndex);

	draw_.drawGameObject(wall, maxLines_);
}


void Game::startGame()
{
	bool topLeft, topRight, bottonLeft, bottonRigth;
	draw_.showCursor(false);

	for (int i = maxLines_ - 1; i >= 0; i--)
	{
		addNewBorder(borderlist_, leftX_, rightX_, i);
	}

	while (true)
	{
		while (!control_.pause(&draw_))
		{
			control_.exitGame();
			system("cls");

			for (int i = 0; i < maxLines_ * 2; i++)
				borderManagement(borderlist_.getElem(i)->data);

			draw_.setColor(Yellow, Black);

			for (int i = 0; i < wallList_.getCount(); i++)
				wallManagement(wallList_.getElem(i)->data, i);

			draw_.setColor(White, Black);
			drawCar(draw_, myCar_, maxLines_);
			drawInterface(draw_, myCar_, distance_);
			borderlist_.delTail();
			borderlist_.delTail();
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
