#include "Game.h"



Game::Game(int maxLines)
{
	this->maxLines = maxLines;
	//добавление в список начальных бардюров
	for (int i = maxLines - 1; i >= 0; i--)
	{
		addNewBorder(borderlist, leftX, rightX, i);
	}
}


Game::~Game()
{
	borderlist.DelAll();
	wallList.DelAll();
}

void Game::addNewBorder(List & borderlist, int & leftX, int & rightX, int y)
{
	//эмул€ци€ неровной дороги
	if (rand() % 10 > 6 && leftX < 10) leftX++;
	else if (rand() % 10 > 6 && leftX > 0) leftX--;
	borderlist.AddHead(new Border(2 + leftX, y));
	if (rand() % 10 > 6 && rightX < 10) rightX++;
	else if (rand() % 10 > 6 && rightX > 0) rightX--;
	borderlist.AddHead(new Border(50 + rightX, y));
}

void Game::DrawCar(Draw & draw, GameObject & car, int maxLines)
{
	draw.SetColor(Red, Black);
	draw.DrawGameObject(&car, maxLines);
	draw.SetColor(White, Black);
}

void Game::DrawInterface(Draw & draw, MyCar & car, int distance)
{
	draw.SetColor(LightCyan, Black);
	draw.GotoXY(55, 5);
	printf("Speed: %d ", 10 + car.GetSpeed() * 10);
	draw.GotoXY(55, 7);
	printf("Distance: %d ", distance);
	draw.SetColor(White, Black);
}

void Game::GameOver(Draw & draw, int distance)
{
	system("cls");
	draw.SetColor(Yellow, Black);
	draw.GotoXY(31, 17);
	printf("GAME OVER");
	draw.GotoXY(23, 20);
	printf("You drove %d kilometers", distance);
	Sleep(5000);
	exit(0);
}

void Game::StartGame()
{
	draw.ShowCursor(false);
	//добавление в список начальных бардюров
	for (int i = maxLines - 1; i >= 0; i--)
	{
		addNewBorder(borderlist, leftX, rightX, i);
	}

	while (true)
	{
		//рабочый цыкл когда пауза не активна
		while (!control.Pause(&draw))
		{
			//контроль за клавишей выхода из игры
			control.Exit();
			//чистим экран
			system("cls");

			//перебор всех бардюров на дороге
			for (int i = 0; i < maxLines * 2; i++)
			{
				//проверка на столкновение машины с бордюром
				if ((myCar.GetX() <= borderlist.GetElem(i)->data->GetX()) &&
					(myCar.GetX() + myCar.GetViewHeight() - 2 >= borderlist.GetElem(i)->data->GetX()) &&
					(myCar.GetY() <= borderlist.GetElem(i)->data->GetY()) &&
					(myCar.GetY() + myCar.GetViewWidht() - 1 >= borderlist.GetElem(i)->data->GetY()))
				{
					GameOver(draw, distance);
				}
				//отрисовка всех бардюров
				draw.DrawGameObject(borderlist.GetElem(i)->data, maxLines);
				//изменение высоты (симул€ци€ движени€) дороги
				borderlist.GetElem(i)->data->SetY(borderlist.GetElem(i)->data->GetY() + 1);
			}

			draw.SetColor(Yellow, Black);
			//перебор всех стен на дороге
			for (int i = 0; i < wallList.GetCount(); i++)
			{
				//проверка на столкновение машины со стеной
				if ((myCar.GetX() <= wallList.GetElem(i)->data->GetX() + wallList.GetElem(i)->data->GetViewHeight() - 2) &&
					(myCar.GetX() + myCar.GetViewHeight() - 2 >= wallList.GetElem(i)->data->GetX()) &&
					(myCar.GetY() <= wallList.GetElem(i)->data->GetY() + wallList.GetElem(i)->data->GetViewWidht() - 1) &&
					(myCar.GetY() + myCar.GetViewWidht() - 1 >= wallList.GetElem(i)->data->GetY()))
				{
					GameOver(draw, distance);
				}
				//отрисовка стены
				draw.DrawGameObject(wallList.GetElem(i)->data, maxLines);
				//изменение высоты (симул€ци€ движени€) стены
				wallList.GetElem(i)->data->SetY(wallList.GetElem(i)->data->GetY() + 1);
				//удалени€ стены из списка при выходе за экран
				if (wallList.GetElem(i)->data->GetY() > maxLines) wallList.Del(i);
			}
			draw.SetColor(White, Black);
			//отрисовка автомобил€ игрока
			DrawCar(draw, myCar, maxLines);
			//отрисовка пользовательского интерфейса
			DrawInterface(draw, myCar, distance);

			//”даление бардюров, которые вышли за экран
			borderlist.DelTail();
			borderlist.DelTail();
			//добавление новых бардюров
			addNewBorder(borderlist, leftX, rightX, 0);
			//по€ление новой стены на дороге
			if (rand() % 100 < 15) wallList.AddHead(new Wall(rand() % 45 + 10, -3));
			//контроль за клавишали управлени€ машиной игрока
			control.CarControl(&myCar);
			//пауза при отрисовке на консоле
			Sleep(500 - 30 * myCar.GetSpeed());
			//увеличиваем счЄтчик пройденной дистанции
			distance++;
		}
		//контроль за клавишей выхода из игры
		control.Exit();
		//задержка при паузе
		Sleep(500);
	}
}
