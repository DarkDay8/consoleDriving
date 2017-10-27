#pragma once
class GameObject
{
protected:
	//начальная координата по х (верхний левый угол)
	int x;
	//начальная координата по н (верхний левый угол)
	int y;
	//изображение обьекта 
	char ** view;
	//ширина изображения (+ символ конца строки)
	int viewHeight;
	//Высота изображения
	int viewWidht;
public:
	GameObject();
	~GameObject();
	//модификаторы
	void SetX(int x);
	void SetY(int y);
	//методы аксессоры 
	int GetX();
	int GetY();
	int GetViewWidht();
	int GetViewHeight();
	char ** GetView();
	//заглушка чтобы не создавать экземпляры базового класса
	virtual bool IsDead() = 0;
};

