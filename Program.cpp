#include "Program.h"

void Program::readInputFromFile(std::string path)
{
	std::fstream inputFile;
	inputFile.open(path, std::ios::in);
	if (inputFile.good())
	{
		std::string line, code = "";
		while (!inputFile.eof())
		{
			std::getline(inputFile, line);
			code += line;
		}
		
		inputFile.close();
		setCode(line);
	}
	else 
		std::cout << "Invalid input file path!" << std::endl;
}

void Program::interpret()
{
	std::string result = interpreter.start(code);
	if (!pathToReturn.empty())
		writeResultToFile(pathToReturn, result);
	else
		std::cout << result << std::endl;
}

void Program::writeResultToFile(std::string path, std::string result)
{
	std::fstream outputFile;

	outputFile.open(path, std::ios::out | std::ios::trunc);
	outputFile << result;
	outputFile.close();
}





