#pragma once
#include <vector>
#include <string>

class Program
{
	std::vector<int> memory;
public:
	Program();

	void interpret(std::string code);

private:
	bool verify(std::string code);
	int findClosingBracket(std::string code, int iter); //returns position of closing bracket
	int findOpeningBracket(std::string code, int iter);
};

