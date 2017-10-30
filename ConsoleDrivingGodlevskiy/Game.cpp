#include "Game.h"



Game::Game(int maxLines)
{
	maxLines_ = maxLines;

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

void Game::startGame()
{
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
			{
				if ((myCar_.getX() <= borderlist_.getElem(i)->data->getX()) &&
					(myCar_.getX() + myCar_.getViewHeight() - 2 >= borderlist_.getElem(i)->data->getX()) &&
					(myCar_.getY() <= borderlist_.getElem(i)->data->getY()) &&
					(myCar_.getY() + myCar_.getViewWidht() - 1 >= borderlist_.getElem(i)->data->getY()))
				{
					gameOver(draw_, distance_);
				}

				draw_.drawGameObject(borderlist_.getElem(i)->data, maxLines_);
				borderlist_.getElem(i)->data->setY(borderlist_.getElem(i)->data->getY() + 1);
			}

			draw_.setColor(Yellow, Black);

			for (int i = 0; i < wallList_.getCount(); i++)
			{
				if ((myCar_.getX() <= wallList_.getElem(i)->data->getX() + wallList_.getElem(i)->data->getViewHeight() - 2) &&
					(myCar_.getX() + myCar_.getViewHeight() - 2 >= wallList_.getElem(i)->data->getX()) &&
					(myCar_.getY() <= wallList_.getElem(i)->data->getY() + wallList_.getElem(i)->data->getViewWidht() - 1) &&
					(myCar_.getY() + myCar_.getViewWidht() - 1 >= wallList_.getElem(i)->data->getY()))
				{
					gameOver(draw_, distance_);
				}

				draw_.drawGameObject(wallList_.getElem(i)->data, maxLines_);
				wallList_.getElem(i)->data->setY(wallList_.getElem(i)->data->getY() + 1);

				if (wallList_.getElem(i)->data->getY() > maxLines_)
					wallList_.del(i);
			}
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
