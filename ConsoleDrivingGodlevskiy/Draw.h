#ifndef DRAW_H
#define DRAW_H

#include <windows.h>
#include <iostream>
#include "GameObject.h"

// Colors
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

class Draw
{
public:
	Draw();
	~Draw();

	void showCursor(bool visible);
	void setColor(ConsoleColor text, ConsoleColor background);
	void gotoXY(int x, int y);
	void writeStr(int x, int y, const char* str);
	void drawGameObject(GameObject* gameObject, int maxY);
};

extern HANDLE hStdOut;
extern HANDLE hStdIn;

#endif // DRAW_H