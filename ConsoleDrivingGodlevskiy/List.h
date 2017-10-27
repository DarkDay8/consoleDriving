#pragma once;
#include "GameObject.h"

struct Elem
{
	GameObject * data; // ������
	Elem *next, *prev;
};

class List
{
	// ������, �����
	Elem *Head, *Tail;
	// ���������� ���������
	int Count;

public:

	// �����������
	List();

	// ����������� �����������
	List(const List&);

	// ����������
	~List();

	// �������� ���������� ���������
	int GetCount();

	// �������� ������� ������
	Elem* GetElem(int);

	// ������� ���� ������
	void DelAll();

	// �������� �������� �� �������
	void Del(int pos);

	// ������� �������� � �������� �������
	void Insert(GameObject * data, int pos);

	// ���������� � ����� ������
	void AddTail(GameObject * data);

	// ���������� � ������ ������
	void AddHead(GameObject * data);

	//�������� ��������� ��������
	void DelHead();

	//�������� ���������� ��������
	void DelTail();

	//���������� ��������� =
	List& operator = (const List&);
};
