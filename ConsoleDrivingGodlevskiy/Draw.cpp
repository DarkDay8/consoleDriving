#include "Draw.h"
#include <windows.h>
#include "Draw.h"
#include <iostream>
using namespace std;

// Хендлы консоли
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

Draw::Draw()
{
}


Draw::~Draw()
{
}



// Показываем/прячем текстовый курсор
void Draw::ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), visible };
	SetConsoleCursorInfo(hStdOut, &cci);
}

// Устанавливает цвет символов и фона
void Draw::SetColor(ConsoleColor text, ConsoleColor background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// Перемещает курсор в заданную позицию
void Draw::GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

// Выводит заданную строку в заданную позицию
void Draw::WriteStr(int X, int Y, const char *Str)
{
	GotoXY(X, Y);
	cout << Str << flush;
}

//Выводит игровой обект на экран
void Draw::DrawGameObject(GameObject * gameObject, int maxY)
{
	for (int i = 0; i < gameObject->GetViewWidht(); i++)
	{
		if ((gameObject->GetY() + i < maxY))
			WriteStr(gameObject->GetX(), gameObject->GetY() + i, gameObject->GetView()[i]);
	}
}
