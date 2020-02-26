#include "Program.h"
#include <iostream>
#include <conio.h>


Program::Program()
{
	memory.push_back(0);
}

void Program::interpret(std::string code)
{
	int memIterator = 0, previousOpeningBracket;

	if (!verify(code))
	{
		std::cout << "Unmatching brackets!" << std::endl;
		return;
	}

	char c;
	for (int i = 0; i < code.length(); ++i) //i is the index of current instruction
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
			std::cout << (char)(memory[memIterator]%128);
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
			i = findOpeningBracket(code, i)-1;

	}
	
}


bool Program::verify(std::string code)
{
	int openingBrackets = 0, closingBrackets = 0;
	for (char c : code)
	{
		if (c == '[')
			openingBrackets++;
		else if (c == ']')
			closingBrackets++;
	}

	if (openingBrackets == closingBrackets)
		return true;
	else
		return false;
}

int Program::findClosingBracket(std::string code, int iter)
{
	int pos = 0, openingBrackets = 0;
	for (int i = iter+1; i < code.length(); ++i)
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

int Program::findOpeningBracket(std::string code, int iter)
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


