#pragma once
#include "node.h"

#ifndef LINKEDLIST
#define LINKEDLIST

class LinkedList {
	node *head;
	node *tail;
	int count;
	bool emptyList;
public:
	LinkedList();
	node * getHead();
	node * getTail();
	void adjustTail();
	int getSize();
	void addToTail(node &nod);
	void addToHead(node &nod);
	void addToPos(node &nod, int pos);
	void remove(node &nod);
	void removeTail();
	void removeAll();
	void displayAll();
	void displaySize();
};

#endif