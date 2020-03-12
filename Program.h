#pragma once
#include "Interpreter.h"
#include <iostream>
#include <fstream>

class Program
{
	std::string pathToReturn = "", code;
	Interpreter interpreter;

public:
	void readInputFromFile(std::string path);
	void interpret();

	inline void setPathToReturn(std::string path)
	{
		pathToReturn = path;
	}

	inline void setCode(std::string _code)
	{
		code = _code;
	}

	inline bool isCodeSet()
	{
		return !code.empty();
	}

private:
	void writeResultToFile(std::string path);
};

