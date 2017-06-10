#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	emptyList = true;
	head = NULL;
	tail = NULL;
	count = 0;
}

node * LinkedList::getHead()
{
	return head;
}

node * LinkedList::getTail()
{
	return tail;
}

void LinkedList::adjustTail()
{
	node * curr = head;
	while (curr->ptr != NULL) // moves and find the actual last node in the list
	{
		curr = curr->ptr;
	}
	tail = curr; // tail points to the last value in the updated list
}

int LinkedList::getSize()
{
	return count;
}

void LinkedList::addToTail(node &nod)
{
	if (emptyList == true)
	{
		head = &nod;
		head->ptr = NULL;
		tail = head;
		count = 1;
		emptyList = false;
	}
	else
	{
		tail->ptr = &nod;
		tail = &nod;
		tail->ptr = NULL;
		count++;
	}
}

void LinkedList::addToHead(node &nod)
{
	if (emptyList == true)
	{
		head = &nod;
		head->ptr = NULL;
		tail = head;
		count = 1;
		emptyList = false;
	}
	else
	{
		node * test = &nod;
		test->ptr = head;
		head = test;
		adjustTail();
		count++;
	}
}

void LinkedList::addToPos(node &nod, int pos)
{
	if (pos <= 0 || pos > (getSize() + 2))
	{
		cout << "Invalid position. ";
		displaySize();
	}
	else if (emptyList == true || pos == 1)
		addToHead(nod);
	else if (pos == (getSize() + 1))
		addToTail(nod);
	else
	{
		node * curr = head;
		node * toAdd = &nod;
		for (int i = 2; i < pos; i++)
			curr = curr->ptr;
		toAdd->ptr = curr->ptr;
		curr->ptr = toAdd;
		adjustTail();
		count++;
	}
}

void LinkedList::remove(node &nod)
{
	if(emptyList == true)
	{
		cout << "The list is empty!" << "\n\n";
	}
	else
	{
		node * test = head; // test points to the beggining of the list
		while (test != &nod) // test moves and match to the node to delete
		{
			test = test->ptr;
		}
		if(test == head) // if node to delete is the first of the list
		{
			if(test == tail) // if the first is the only one in the list
			{
				removeAll();
			}
			else // if there is more nodes in the list
			{
				head = test->ptr; // remove the first one from the list and set the next one as head
				adjustTail();
				count--;
			}
		}
		else if(test == tail) // else if node to delete is the last of the list with more than one node
		{
			node * temp = head; // temp points to the beggining of the list
			while(temp->ptr != tail) // find the one before tail
			{
				temp = temp->ptr;
			}
			temp->ptr = NULL; // set the pointing value to NULL
			tail = temp; // tail become the previous node found
			count--;
		}
		else // else it is a node in the middle of a list with at least 3 nodes.
		{
			node * next = test->ptr; // "next" receives the address of the next node
			node * prev = head; // prev points to the beggining of the list
			while (prev->ptr != test) // moves and find the one before the node that we want to delete
			{
				prev = prev->ptr;
			}
			prev->ptr = next; // the previous points now to the next in the list after the deleted node
			adjustTail();
			count--;
		}
	}
}
void LinkedList::removeTail()
{
	if (emptyList == true)
	{
		cout << "The list is empty!" << "\n\n";
	}
	else
	{
		node * curr = head; // test points to the beggining of the list
		node * last = tail;
		if (curr == last) // if node to delete is the first of the list
		{
			removeAll();
		}
		else
		{
			while (curr->ptr != last) // test moves and match to the node to delete
			{
				curr = curr->ptr;
			}
			curr->ptr = NULL;
			tail = curr;
			count--;
		}
	}
}

void LinkedList::removeAll()
{
	head = NULL;
	tail = NULL;
	count = 0;
	emptyList = true;
}

void LinkedList::displayAll()
{
	if(emptyList == true)
	{
		cout << "The list is empty!\n\n";
	}
	else
	{
		node * test = head;
		while (test != NULL)
		{
			if (test->data1)
				cout << "Value of node: " << test->data1 << "\nAddress of node: " << test << "\nNode pointing to: " << test->ptr << "\n\n";
			if (test->data2)
				cout << "Value of node: " << test->data2 << "\nAddress of node: " << test << "\nNode pointing to: " << test->ptr << "\n\n";
			if (test->data3)
				cout << "Value of node: " << test->data3 << "\nAddress of node: " << test << "\nNode pointing to: " << test->ptr << "\n\n";
			if (test->data4 != "")
				cout << "Value of node: " << test->data4 << "\nAddress of node: " << test << "\nNode pointing to: " << test->ptr << "\n\n";
			if (test->data5)
				cout << "Value of node: " << test->data5 << "\nAddress of node: " << test << "\nNode pointing to: " << test->ptr << "\n\n";
			if (test->data6)
				cout << "Value of node: " << boolalpha << test->data6 << "\nAddress of node: " << test << "\nNode pointing to: " << test->ptr << "\n\n";

			test = test->ptr;
		}
	}
}

void LinkedList::displaySize()
{
	cout << "The size of the List is: " << getSize() << "\n\n";
}