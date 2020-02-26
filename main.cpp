#include <iostream>
#include <string>
#include <fstream>
#include "Program.h"

int main(int argc, char **argv)
{
	std::string code = "";
	std::cin >> code;
	Program program;
	program.interpret(code);
}