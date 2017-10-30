#include "List.h"

using namespace std;

List::List()
{
	head_ = tail_ = nullptr;
	count_ = 0;
}

List::List(const List& list)
{
	head_ = tail_ = nullptr;
	count_ = 0;
	Elem* temp = list.head_;

	while (temp != nullptr)
	{
		addTail(temp->data);
		temp = temp->next;
	}
}

List::~List()
{
	delAll();
}

void List::addHead(GameObject* data)
{
	Elem* temp = new Elem;
	temp->prev = nullptr;
	temp->data = data;
	temp->next = head_;

	if (head_ != nullptr)
		head_->prev = temp;
	head_ = temp;

	if (tail_ == nullptr)
		tail_ = temp;
	count_++;
}

void List::addTail(GameObject* data)
{
	Elem * temp = new Elem;
	temp->next = nullptr;
	temp->data = data;
	temp->prev = tail_;

	if (tail_ != nullptr)
		tail_->next = temp;
	tail_ = temp;

	if (head_ == nullptr)
		head_ = temp;
	count_++;
}

void List::delHead()
{
	if (head_ != nullptr)
	{
		Elem* temp = head_;
		head_ = head_->next;

		if (head_ != nullptr)
			head_->prev = nullptr;
		else
			tail_ = nullptr;
		delete temp;
		count_--;
	}
}

void List::delTail()
{
	if (tail_ != nullptr)
	{
		Elem* temp = tail_;
		tail_ = tail_->prev;

		if (tail_ != nullptr)
			tail_->next = nullptr;
		else
			head_ = nullptr;
		delete temp;
		count_--;
	}
}

void List::insert(GameObject* data, int pos)
{
	if (pos < 0 || pos > count_)
		return;

	if (pos == 0)
	{
		addHead(data);
		return;
	}

	if (pos == count_)
	{
		addTail(data);
		return;
	}
	Elem* current = nullptr;

	if (pos < count_ / 2)
	{
		current = head_;
		int i = 0;
		while (i < pos)
		{
			current = current->next;
			i++;
		}
	}
	else
	{
		current = tail_;
		int i = count_ - 1;
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
	count_++;
}

void List::del(int pos)
{
	if (pos < 0 || pos >= count_)
		return;

	if (pos == 0)
	{
		delHead();
		return;
	}

	if (pos == count_ - 1)
	{
		delTail();
		return;
	}
	Elem* delElement = nullptr;

	if (pos < count_ / 2)
	{
		delElement = head_;
		int i = 0;

		while (i < pos)
		{
			delElement = delElement->next;
			i++;
		}
	}
	else
	{
		delElement = tail_;
		int i = count_ - 1;

		while (i > pos)
		{
			delElement = delElement->prev;
			i--;
		}
	}
	delElement->prev->next = delElement->next;
	delElement->next->prev = delElement->prev;
	delete delElement;
	count_--;
}


void List::delAll()
{
	while (head_ != nullptr)
		delHead();
}

int List::getCount()
{
	return count_;
}

Elem* List::getElem(int pos)
{
	Elem* temp = head_;
	if (pos < 0 || pos >= count_)
		return nullptr;
	int i = 0;
	while (i < pos)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

List& List::operator = (const List& list)
{
	if (this == &list)
		return *this;
	delAll();
	Elem * temp = list.head_;
	while (temp != nullptr)
	{
		addTail(temp->data);
		temp = temp->next;
	}
	return *this;
}



