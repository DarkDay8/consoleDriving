#pragma once;
#include "GameObject.h"

struct Elem
{
	GameObject * data; // данные
	Elem *next, *prev;
};

class List
{
	// Голова, хвост
	Elem *Head, *Tail;
	// Количество элементов
	int Count;

public:

	// Конструктор
	List();

	// Конструктор копирования
	List(const List&);

	// Деструктор
	~List();

	// Получить количество элементов
	int GetCount();

	// Получить элемент списка
	Elem* GetElem(int);

	// Удалить весь список
	void DelAll();

	// Удаление элемента по индексу
	void Del(int pos);

	// Вставка элемента в заданную позицию
	void Insert(GameObject * data, int pos);

	// Добавление в конец списка
	void AddTail(GameObject * data);

	// Добавление в начало списка
	void AddHead(GameObject * data);

	//Удаление головного элемента
	void DelHead();

	//Удаление хвостового элемента
	void DelTail();

	//перегрузка оператора =
	List& operator = (const List&);
};
