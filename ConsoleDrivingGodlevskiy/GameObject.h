#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//#include <iostream>>


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
	//std::string* getView2();
	virtual bool isDead() = 0;

protected:
	int x_;
	int y_;
	char** view_;
	//std::string* view2_;
	int viewHeight_;
	int viewWidht_;
};
#else
#endif // GAMEOBJECT_H