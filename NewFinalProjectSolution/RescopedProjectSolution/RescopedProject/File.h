#pragma once
#include <string>
#include <iostream>
#include <fstream>
class File
{
public:
	File();
	~File();
	void init();
	void PrintToFile(std::string);
	void CloseFile();
private:
	std::ofstream *file;
	
};

