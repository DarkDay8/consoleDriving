#pragma once
#include <Windows.h>
#include <iostream>
#include <ctime>
#include "Draw.h"
#include "MyCar.h"
#include "GameObject.h"
#include "Border.h"
#include "Control.h"
#include "List.h"
#include "Wall.h"

class Game
{
protected:
	Control control;
	MyCar myCar;
	Draw draw;
	List borderlist;
	List wallList;
	int distance = 0;
	int leftX = 0;
	int rightX = 0;
	int maxLines;
public:
	Game(int maxLines);
	~Game();
	//���������� ���� ������
	void addNewBorder(List &borderlist, int &leftX, int &rightX, int y);
	//��������� ���������� ������
	void DrawCar(Draw &draw, GameObject &car, int maxLines);
	//��������� ����������������� ����������
	void DrawInterface(Draw &draw, MyCar &car, int distance);
	//��������� ������ ���� ����� � ����������� ������� �� ����
	void GameOver(Draw & draw, int distance);
	//������ ����
	void StartGame();
};

