#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	// ���������� ������ ����
	Head = nullptr;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(GameObject * data)
{
	// �������� ������ ��������
	Element * temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� - �������� ������� ������
	temp->Next = Head;

	// ����� ������� ���������� �������� ��������� ������
	Head = temp;

	Count++;
}

void List::Del()
{
	if(Head)
	{
		// ���������� ����� ��������� ��������
		Element * temp = Head->Next;
		// ������������� ������ �� ��������� �������
		delete Head;
		// ������� ������ �������� �������
		Head = temp;
		Count--;
	}
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while(Head != nullptr)
		// ������� �������� �� ������
		Del();
}


