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

void addNewBorder(List &borderlist, int &leftX, int &rightX, int y);

void DrawCar(Draw &draw, GameObject &car, int maxLines);

void GameOver(Draw & draw, int distance);