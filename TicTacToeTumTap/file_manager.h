#pragma once
#include "stdafx.h"

#ifndef FILE_MANAGER
#define FILE_MANAGER

class FileManager
{
	int nLines;
	string content;
	string * content_lines;
	string fileName;

public:
	FileManager(string fileName);
	void loadData(string fileName);
	void saveData(string fileName, string content);
	int linesCount();
	void set_nLines(string content);
	string getContent();
	void setContent(string newContent);
	void convertToLines();
	string * getContentLines();
};

#endif