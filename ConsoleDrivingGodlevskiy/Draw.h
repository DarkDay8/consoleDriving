#pragma once
#define __CONSOLELIB_H__
#include <windows.h>
#include <iostream>
#include "GameObject.h"

// Цвета
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
	// Показываем/прячем текстовый курсор
	void ShowCursor(bool visible);

	// Устанавливает цвет символов и фона
	void SetColor(ConsoleColor text, ConsoleColor background);

	// Перемещает курсор в заданную позицию
	void GotoXY(int X, int Y);

	// Выводит заданную строку в заданную позицию
	void WriteStr(int X, int Y, const char *Str);

	//Выводит игровой обект на экран
	void DrawGameObject(GameObject *gameObject, int maxY);

};
// Хендлы консоли
extern HANDLE hStdOut;
extern HANDLE hStdIn;

