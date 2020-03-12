#include "Program.h"

int main(int argc, char **argv)
{
	Program program;
	for (int i = 1; i < argc - 1; ++i)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i + 1][1])
			{
			case 'i': // -i in.txt 
				program.readInputFromFile(argv[i + 1]);
				break;
			case 'o': // -o out.txt
				program.setPathToReturn(argv[i + 1]);
				break;
			}
		}
		else if (i == argc - 1)
			program.setCode(argv[i]);
	}

	if (!program.isCodeSet())
	{
		std::string code;
		std::cin >> code;
		program.setCode(code);
	}

	program.interpret();
	return 0;
}