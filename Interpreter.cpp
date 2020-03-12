#include "Interpreter.h"

Interpreter::Interpreter()
{
	memory.push_back(0);
}

std::string Interpreter::start(std::string code)
{
	size_t memIterator = 0, previousOpeningBracket;

	CodeStatus st = verifyCode(code);

	if (st == missingBracket)
		return "Unmatching brackets!";
	else if (st == invalidCharacters)
		return "Invalid characters!";

	char c;
	for (size_t i = 0; i < code.length(); ++i) //i is the index of current instruction
	{
		c = code[i];

		if (c == '+')
			memory[memIterator]++;

		else if (c == '-')
			memory[memIterator]--;

		else if (c == '>')
		{
			memIterator++;
			if (memIterator >= memory.size())
				memory.push_back(0);
		}
		else if (c == '<')
		{
			if (memIterator > 0)
				memIterator--;
		}
		else if (c == '.')
			result += (char)(memory[memIterator] % 128);
		else if (c == ',')
		{
			char get = _getch();
			memory[memIterator] = get;
		}
		else if (c == '[')
		{
			if (memory[memIterator] == 0)
				i = findClosingBracket(code, i);
		}
		else if (c == ']')
			i = findOpeningBracket(code, i) - 1;
	}
	return result;
}

CodeStatus Interpreter::verifyCode(std::string code)
{
	int openingBrackets = 0, closingBrackets = 0;
	for (char c : code)
	{
		if (c == '[')
			openingBrackets++;
		else if (c == ']')
			closingBrackets++;
		
		if (std::find(possibleInstructions.begin(), possibleInstructions.end(), c) == possibleInstructions.end())
			return invalidCharacters;
	}

	if (openingBrackets == closingBrackets)
		return valid;
	else
		return missingBracket;
}

int Interpreter::findClosingBracket(std::string code, int iter)
{
	size_t pos = 0, openingBrackets = 0;
	for (size_t i = iter + 1; i < code.length(); ++i)
	{
		if (code[i] == '[')
			openingBrackets++;
		else if (code[i] == ']')
		{
			if (openingBrackets == 0)
				return i;
			else
				openingBrackets--;
		}

	}
	return -1;
}

int Interpreter::findOpeningBracket(std::string code, int iter)
{
	int pos = 0, closingBrackets = 0;
	for (int i = iter - 1; i >= 0; --i)
	{
		if (code[i] == ']')
			closingBrackets++;
		else if (code[i] == '[')
		{
			if (closingBrackets == 0)
				return i;
			else
				closingBrackets--;
		}

	}
	return -1;
}
