#include <Windows.h>
#include <iostream>
#include <ctime>
#include "ConsoleDrivingGodlevskiy.h"
#include "Draw.h"
#include "MyCar.h"
#include "GameObject.h"
#include "Border.h"
#include "Control.h"

int main()
{
	system("mode con cols=70 lines=30");
	srand(time(0));

	Control control;
	MyCar myCar;
	Draw draw;
	Border * leftBorder = new Border[30];
	Border * rightBorder = new Border[30];

	int leftX = 0;
	int rightX = 0;

	for (int i = 0; i < 30; i++)
	{
		if (rand() % 10 > 6 && leftX < 10) leftX++;
		else if (rand() % 10 > 6 && leftX > 0) leftX--;
		leftBorder[i] = Border(2 + leftX, i);
		if (rand() % 10 > 6 && rightX < 10) rightX++;
		else if (rand() % 10 > 6 && rightX > 0) rightX--;
		rightBorder[i] = Border(50 + rightX, i);
	}

	GameObject ** all;
	all = new GameObject *[61];
	for (int i = 0; i < 30; i++)
	{
		all[i] = &leftBorder[i];
		all[i + 30] = &rightBorder[i];
	}
	all[60] = &myCar;

	//for (size_t i = 0; i < 61; i++)
	//{
	//	draw.DrawGameObject(all[i], 31);
	//}

	//draw.DrawGameObject(&myCar, 50);


	while (true)
	{
		control.CarControl(&myCar);

		system("cls");
		for (size_t i = 0; i < 61; i++)
		{
			draw.DrawGameObject(all[i], 31);
		}
		Sleep(500 - 3 * myCar.GetSpeed());

	}

	system("pause");
}

