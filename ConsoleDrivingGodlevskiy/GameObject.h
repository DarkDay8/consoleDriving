#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getViewWidht();
	int getViewHeight();
	char** getView();
	virtual bool isDead() = 0;

protected:
	int x_;
	int y_;
	char** view_;
	int viewHeight_;
	int viewWidht_;
};

#endif // GAMEOBJECT_H