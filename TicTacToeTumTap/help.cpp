#include "stdafx.h"
#include "help.h"

Help::Help()
{
	
}

string Help::h_getRules()
{
	ifstream gRules;	
	gRules.open("gRules.txt");
	int count = 0;
	string rules;
	char r = gRules.get();
	while(gRules.good())
	{
		if (r == '\n')
			count++;
		rules = rules + r;
		r = gRules.get();
	}
	count++;

	cout << rules << endl;
	cout << "Number of lines: " << count << endl;

	gRules.close();
	return rules;
}


