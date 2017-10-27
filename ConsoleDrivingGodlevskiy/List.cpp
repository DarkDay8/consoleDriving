#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	Head = Tail = nullptr;
	Count = 0;
}

List::List(const List & L)
{
	Head = Tail = nullptr;
	Count = 0;
	Elem * temp = L.Head;
	while (temp != nullptr)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

List::~List()
{
	DelAll();
}

void List::AddHead(GameObject * data)
{
	Elem * temp = new Elem;
	temp->prev = nullptr;
	temp->data = data;
	temp->next = Head;
	if (Head != nullptr)
		Head->prev = temp;
	Head = temp;
	if (Tail == nullptr)
		Tail = temp;
	Count++;
}

void List::AddTail(GameObject * data)
{
	Elem * temp = new Elem;
	temp->next = nullptr;
	temp->data = data;
	temp->prev = Tail;
	if (Tail != nullptr)
		Tail->next = temp;
	Tail = temp;
	if (Head == nullptr)
		Head = temp;
	Count++;
}

void List::DelHead()
{
	if (Head != nullptr)
	{
		Elem *temp = Head;
		Head = Head->next;
		if (Head != nullptr)
			Head->prev = nullptr;
		else
			Tail = nullptr;
		delete temp;
		Count--;
	}
}

void List::DelTail()
{
	if (Tail != nullptr)
	{
		Elem *temp = Tail;
		Tail = Tail->prev;
		if (Tail != nullptr)
			Tail->next = nullptr;
		else
			Head = nullptr;
		delete temp;
		Count--;
	}
}

void List::Insert(GameObject * data, int pos)
{
	if (pos < 0 || pos > Count)
		return;
	if (pos == 0)
	{
		AddHead(data);
		return;
	}
	if (pos == Count)
	{
		AddTail(data);
		return;
	}
	Elem *current = nullptr;
	if (pos < Count / 2)
	{
		current = Head;
		int i = 0;
		while (i < pos)
		{
			current = current->next;
			i++;
		}
	}
	else
	{
		current = Tail;
		int i = Count - 1;
		while (i > pos)
		{
			current = current->prev;
			i--;
		}
	}
	Elem *temp = new Elem;
	temp->data = data;
	temp->prev = current->prev;
	temp->next = current;
	current->prev->next = temp;
	current->prev = temp;
	Count++;
}

void List::Del(int pos)
{
	if (pos < 0 || pos >= Count)
		return;
	if (pos == 0)
	{
		DelHead();
		return;
	}
	if (pos == Count - 1)
	{
		DelTail();
		return;
	}
	Elem *delElement = nullptr;
	if (pos < Count / 2)
	{
		delElement = Head;
		int i = 0;
		while (i < pos)
		{
			delElement = delElement->next;
			i++;
		}
	}
	else
	{
		delElement = Tail;
		int i = Count - 1;
		while (i > pos)
		{
			delElement = delElement->prev;
			i--;
		}
	}
	delElement->prev->next = delElement->next;
	delElement->next->prev = delElement->prev;
	delete delElement;
	Count--;
}


void List::DelAll()
{
	while (Head != nullptr)
		DelHead();
}

int List::GetCount()
{
	return Count;
}

Elem * List::GetElem(int pos)
{
	Elem *temp = Head;
	if (pos < 0 || pos >= Count)
		return nullptr;
	int i = 0;
	while (i < pos)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

List& List::operator = (const List & L)
{
	if (this == &L)
		return *this;
	DelAll();
	Elem * temp = L.Head;
	while (temp != nullptr)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}



