#pragma once
#include <vector>
#include <string>
#include <conio.h>
#include <algorithm>

enum CodeStatus
{
	valid,
	missingBracket,
	invalidCharacters
};

class Interpreter
{
	std::vector<int> memory;
	const std::vector<char> possibleInstructions = {'+', '-', ',', '.', '[', ']'};
	std::string result = "";
public:
	Interpreter();
	std::string start(std::string code);

private:
	int findClosingBracket(std::string code, int iter);
	int findOpeningBracket(std::string code, int iter);
	CodeStatus verifyCode(std::string code);
};


