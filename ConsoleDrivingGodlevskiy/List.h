#ifndef LIST_H
#define LIST_H

#include "GameObject.h"

struct Elem
{
	GameObject* data; 
	Elem* next;
	Elem* prev;
};

class List
{
public:
	List();
	List(const List& list);
	~List();
	List& operator = (const List& list);

	int getCount();
	Elem* getElem(int);
	void delAll();
	void del(int pos);
	void insert(GameObject * data, int pos);
	void addTail(GameObject * data);
	void addHead(GameObject * data);
	void delHead();
	void delTail();

private:
	Elem* head_;
	Elem* tail_;
	int count_;
};

#endif // LIST_H