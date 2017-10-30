#include "Draw.h"
using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

Draw::Draw()
{
}

Draw::~Draw()
{
}


void Draw::showCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), visible };
	SetConsoleCursorInfo(hStdOut, &cci);
}

void Draw::setColor(ConsoleColor text, ConsoleColor background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Draw::gotoXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(hStdOut, coord);
}

void Draw::writeStr(int x, int y, const char* str)
{
	gotoXY(x, y);
	cout << str << flush;
}

void Draw::drawGameObject(GameObject* gameObject, int maxY)
{
	for (int i = 0; i < gameObject->getViewWidht(); i++)
	{
		if ((gameObject->getY() + i < maxY) && (gameObject->getY() + i >= 0))
			writeStr(gameObject->getX(), gameObject->getY() + i, gameObject->getView()[i]);
	}
}
