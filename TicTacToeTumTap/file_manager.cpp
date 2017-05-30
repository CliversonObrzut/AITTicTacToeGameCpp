#include "stdafx.h"
#include "file_manager.h"

// Graphical User Interface constructor
// Load data from file passed by its subclass
FileManager::FileManager(string fileName)
{
	loadData(fileName);
	convertToLines();
}

void FileManager::loadData(string fileName)
{
	ifstream file;
	file.open(fileName);
	char r = file.get();
	while (file.good())
	{
		if (r == '\n')
			nLines++;
		content = content + r;
		r = file.get();
	}
	nLines++;
	file.close();
}

void FileManager::saveData(string fileName, string content)
{
	ofstream file;
	file.open(fileName);
	file << content;	
	file.close();
}

int FileManager::linesCount()
{
	return nLines;
}

string FileManager::getContent()
{
	return content;
}

void FileManager::setContent(string newContent)
{
	content = newContent;
	set_nLines(newContent);
}

void FileManager::set_nLines(string content)
{
	int count=0, i = 0;
	char r = content[i];
	while (content[i] != content.length()-1)
	{
		if (r == '\n')
			count++;
		i++;
	}
	count++;
	nLines = count;
}

void FileManager::convertToLines()
{
	content_lines = new string[nLines];
	string s;
	int row = 0;
	char * c = new char[content.length()];
	c = &content[0];
	for(int i = 0; i < content.length(); i++)
	{
		if (c[i] == '\n')
		{
			s = s + c[i];
			content_lines[row] = s;
			row++;
			s = "";
		}
		else
			s = s + c[i];
	}
	content_lines[row] = s;
}

string* FileManager::getContentLines()
{
	return content_lines;
}


