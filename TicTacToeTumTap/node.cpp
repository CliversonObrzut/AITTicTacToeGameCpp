#include "stdafx.h"
#include "node.h";

	node::node()
	{
		data1 = NULL;
		data2 = NULL;
		data3 = NULL;
		data4 = "";
		data5 = NULL;
		data6 = NULL;
		ptr = NULL;
	}

	node::node(int d)
	{
		data1 = d;
		data2 = NULL;
		data3 = NULL;
		data4 = "";
		data5 = NULL;
		data6 = NULL;
		ptr = NULL;
	}

	node::node(double d)
	{
		data1 = NULL;
		data2 = d;
		data3 = NULL;
		data4 = "";
		data5 = NULL;
		data6 = NULL;
		ptr = NULL;
	}

	node::node(float d)
	{
		data1 = NULL;
		data2 = NULL;
		data3 = d;
		data4 = "";
		data5 = NULL;
		data6 = NULL;
		ptr = NULL;
	}

	node::node(string d)
	{
		data1 = NULL;
		data2 = NULL;
		data3 = NULL;
		data4 = d;
		data5 = NULL;
		data6 = NULL;
		ptr = NULL;
	}

	node::node(char d)
	{
		data1 = NULL;
		data2 = NULL;
		data3 = NULL;
		data4 = "";
		data5 = d;
		data6 = NULL;
		ptr = NULL;
	}

	node::node(bool d)
	{
		data1 = NULL;
		data2 = NULL;
		data3 = NULL;
		data4 = "";
		data5 = NULL;
		data6 = d;
		ptr = NULL;
	}