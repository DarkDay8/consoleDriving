#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	// Изначально список пуст
	Head = nullptr;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(GameObject * data)
{
	// создание нового элемента
	Element * temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент - головной элемент списка
	temp->Next = Head;

	// новый элемент становится головным элементом списка
	Head = temp;

	Count++;
}

void List::Del()
{
	if(Head)
	{
		// запоминаем адрес головного элемента
		Element * temp = Head->Next;
		// перебрасываем голову на следующий элемент
		delete Head;
		// удаляем бывший головной элемент
		Head = temp;
		Count--;
	}
}

void List::DelAll()
{
	// Пока еще есть элементы
	while(Head != nullptr)
		// Удаляем элементы по одному
		Del();
}


