#pragma once
class GameObject
{
protected:
	int x;
	int y;
	char ** view;
	int viewHeight;
	int viewWidht;
public:
	GameObject();
	~GameObject();
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
	int GetViewWidht();
	int GetViewHeight();
	char ** GetView();

	virtual bool IsDead() = 0;
};

