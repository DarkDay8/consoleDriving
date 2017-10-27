#pragma once
#define __CONSOLELIB_H__
#include <windows.h>
#include <iostream>
#include "GameObject.h"

// �����
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
	// ����������/������ ��������� ������
	void ShowCursor(bool visible);

	// ������������� ���� �������� � ����
	void SetColor(ConsoleColor text, ConsoleColor background);

	// ���������� ������ � �������� �������
	void GotoXY(int X, int Y);

	// ������� �������� ������ � �������� �������
	void WriteStr(int X, int Y, const char *Str);

	//������� ������� ����� �� �����
	void DrawGameObject(GameObject *gameObject, int maxY);

};
// ������ �������
extern HANDLE hStdOut;
extern HANDLE hStdIn;

