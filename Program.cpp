#include "Program.h"

void Program::readInputFromFile(std::string path)
{
	//reading input from file
}

void Program::interpret()
{
	std::string result = interpreter.start(code);
	if (!pathToReturn.empty())
		writeResultToFile(pathToReturn);
	else
		std::cout << result << std::endl;
}

void Program::writeResultToFile(std::string path)
{
	//writing to file here
}





