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

int main();
//добавление краёв дороги
void addNewBorder(List &borderlist, int &leftX, int &rightX, int y);
//отрисовка автомобиля игрока
void DrawCar(Draw &draw, GameObject &car, int maxLines);
//отрисовка пользовательского интерфейса
void DrawInterface(Draw &draw, MyCar &car, int distance);
//отрисовка экрана Гейм Овера с воследующим выходом из игры
void GameOver(Draw & draw, int distance);