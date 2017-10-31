#include "Draw.h"
using namespace std;



Draw::Draw()
{
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	hStdIn = GetStdHandle(STD_INPUT_HANDLE);
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
	//char* tmp = nullptr;

	for (int i = 0; i < gameObject->getViewWidht(); i++)
	{	
		//tmp = const_cast<char*>(gameObject->getView2()[i].c_str());

		if ((gameObject->getY() + i < maxY) && (gameObject->getY() + i >= 0))
			//writeStr(gameObject->getX(), gameObject->getY() + i, tmp);		
			writeStr(gameObject->getX(), gameObject->getY() + i, gameObject->getView()[i]);
	}
	//tmp = nullptr;
}
