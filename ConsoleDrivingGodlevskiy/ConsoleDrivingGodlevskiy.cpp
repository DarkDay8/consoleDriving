

#include "ConsoleDrivingGodlevskiy.h"

int main()
{
	int maxLines = 30;
	system("mode con cols=70 lines=30");
	srand(time(0));

	Control control;
	MyCar myCar;
	Draw draw;
	List borderlist;
	List wallList;
	int distance = 0;
	int leftX = 0;
	int rightX = 0;

	draw.ShowCursor(false);

	for (int i = maxLines - 1; i >= 0; i--)
	{
		addNewBorder(borderlist, leftX, rightX, i);
	}


	while (true)
	{
		while (!control.Pause(&draw))
		{			
			control.Exit();
			system("cls");

			for (int i = 0; i < maxLines * 2; i++)
			{				
				if ((myCar.GetX() <= borderlist.GetElem(i)->data->GetX()) &&
					(myCar.GetX() + myCar.GetViewHeight() - 2 >= borderlist.GetElem(i)->data->GetX()) &&
					(myCar.GetY() <= borderlist.GetElem(i)->data->GetY()) &&
					(myCar.GetY() + myCar.GetViewWidht()  - 1 >= borderlist.GetElem(i)->data->GetY()))
				{
					GameOver(draw, distance);			
				}
				draw.DrawGameObject(borderlist.GetElem(i)->data, maxLines);					
				borderlist.GetElem(i)->data->SetY(borderlist.GetElem(i)->data->GetY() + 1);
			}

			draw.SetColor(Yellow, Black);
			for (int i = 0; i < wallList.GetCount(); i++)
			{
				if ((myCar.GetX() <= wallList.GetElem(i)->data->GetX() + wallList.GetElem(i)->data->GetViewHeight() - 2) &&
					(myCar.GetX() + myCar.GetViewHeight()  - 2 >= wallList.GetElem(i)->data->GetX()) &&
					(myCar.GetY() <= wallList.GetElem(i)->data->GetY() + wallList.GetElem(i)->data->GetViewWidht() - 1) &&
					(myCar.GetY() + myCar.GetViewWidht()  - 1 >= wallList.GetElem(i)->data->GetY()))
				{
					GameOver(draw, distance);				
				}
				draw.DrawGameObject(wallList.GetElem(i)->data, maxLines);
				wallList.GetElem(i)->data->SetY(wallList.GetElem(i)->data->GetY() + 1);
				if (wallList.GetElem(i)->data->GetY() > maxLines) wallList.Del(i);
			}
			draw.SetColor(White, Black);	
			DrawCar(draw, myCar, maxLines);
			DrawInterface(draw, myCar, distance);

			borderlist.DelTail();
			borderlist.DelTail();
			addNewBorder(borderlist, leftX, rightX, 0);
			if (rand() % 100 < 15) wallList.AddHead(new Wall(rand() % 45 + 10, -3));

			control.CarControl(&myCar);

			Sleep(500 - 30 * myCar.GetSpeed());
			distance++;
		}
		control.Exit();
		Sleep(500);
	}

	system("pause");
}

void addNewBorder(List &borderlist, int &leftX, int &rightX, int y)
{
	if (rand() % 10 > 6 && leftX < 10) leftX++;
	else if (rand() % 10 > 6 && leftX > 0) leftX--;
	borderlist.AddHead(new Border(2 + leftX, y));
	if (rand() % 10 > 6 && rightX < 10) rightX++;
	else if (rand() % 10 > 6 && rightX > 0) rightX--;
	borderlist.AddHead(new Border(50 + rightX, y));
}

void DrawCar(Draw & draw, GameObject & car, int maxLines)
{
	draw.SetColor(Red, Black);
	draw.DrawGameObject(&car, maxLines);
	draw.SetColor(White, Black);
}

void DrawInterface(Draw & draw, MyCar & car, int distance)
{
	draw.SetColor(LightCyan, Black);
	draw.GotoXY(55, 5);
	printf("Speed: %d ", 10 + car.GetSpeed() * 10);
	draw.GotoXY(55, 7);
	printf("Distance: %d ", distance);
	draw.SetColor(White, Black);
}

void GameOver(Draw & draw, int distance)
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


