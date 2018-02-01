#include <iostream>
#include "list.h"

List::List()
{
	first = nullptr;
}

List::~List()
{
	if (!first)
		return;
	Node *temp = first;
	Node *nodeToDelete = temp;
	while (temp->next)
	{
		temp = temp->next;
		delete nodeToDelete;
		nodeToDelete = temp;
	}
	delete nodeToDelete;
}

bool List::exists(int d) const
{
	if (!first)
		return false;
	Node *temp = first;
	do
	{
		if (temp->value == d)
			return true;
		temp = temp->next;
	} while (temp->next);
	if (temp->value == d)
		return true;
	return false;
}

int List::size() const
{
	if (!first)
		return 0;
	Node *temp = first;
	int counter{1};
	while (temp->next)
	{
		temp = temp->next;
		counter++;
	}
	return counter;
}

bool List::empty() const
{
	return first == nullptr; // Kan jag göra så här?
}

void List::insertFirst(int d)
{
	Node *newNode = new Node(d, first);
	first = newNode;
	//std::cout << first->value << " was inserted in the first place." << std::endl;
}

void List::remove(int d, DeleteFlag df)
{
	if (first)
	{
		Node *temp = first;
		switch (df)
		{
		case List::DeleteFlag::LESS:
			if (temp->value < d)
			{
				first = temp->next;
				delete temp;
				return;
			}
			do
			{
				if (temp->next->value < d)
				{
					Node *nodeToDelete = temp->next;
					temp->next = temp->next->next;
					delete nodeToDelete;
					return;
				}
				temp = temp->next;
			} while (temp->next);
			break;
		case List::DeleteFlag::EQUAL:
			if (temp->value == d)
			{
				first = temp->next;
				delete temp;
				return;
			}
			do
			{
				if (temp->next->value == d)
				{
					Node *nodeToDelete = temp->next;
					temp->next = temp->next->next;
					delete nodeToDelete;
					return;
				}
				temp = temp->next;
			} while (temp->next);
			break;
		case List::DeleteFlag::GREATER:
			if (temp->value > d)
			{
				first = temp->next;
				delete temp;
				return;
			}
			do
			{
				if (temp->next->value > d)
				{
					Node *nodeToDelete = temp->next;
					temp->next = temp->next->next;
					delete nodeToDelete;
					return;
				}
				temp = temp->next;
			} while (temp->next);
			break;
		}
	}
}

void List::print() const
{
	if (!first)
	{
		std::cout << "The list is empty.";// << std::endl;
		return;
	}

	Node *temp = first;
	do
	{
		std::cout << temp->value << ", ";// << std::endl;
		temp = temp->next;
	} while (temp->next);
	std::cout << temp->value;// << std::endl;
}
