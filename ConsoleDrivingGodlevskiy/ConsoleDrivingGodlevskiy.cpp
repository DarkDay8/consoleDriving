

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

	int leftX = 0;
	int rightX = 0;

	for (int i = maxLines - 1; i >= 0; i--)
	{
		addNewBorder(borderlist, leftX, rightX, i);
	}

	while (true)
	{
		while (!control.Pause(&draw))
		{
			control.CarControl(&myCar);
			control.Exit();

			system("cls");
			for (int i = 0; i < maxLines * 2; i++)
			{
				draw.DrawGameObject(borderlist.GetElem(i)->data, maxLines);
				borderlist.GetElem(i)->data->SetY(borderlist.GetElem(i)->data->GetY() + 1);
			}
			DrawCar(draw, myCar, maxLines);

			borderlist.DelTail();
			borderlist.DelTail();
			addNewBorder(borderlist, leftX, rightX, 0);

			Sleep(500 - 30 * myCar.GetSpeed());
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



