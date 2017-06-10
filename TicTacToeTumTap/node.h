#pragma once
using namespace std;

#ifndef NODE
#define NODE

class node
{
public:
	int data1;
	double data2;
	float data3;
	string data4;
	char data5;
	bool data6;
	node * ptr;
	node();
	explicit node(int d);
	explicit node(double d);
	explicit node(float d);
	explicit node(string d);
	explicit node(char d);
	explicit node(bool d);
};

#endif

