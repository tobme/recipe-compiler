#include <string>
#include "Scanner.h"
#include<vector>
#include "parser.h"
#include<iostream>

int main(int argc, char* argv[])
{

	Scanner scanner{};

	auto tokens = scanner.read(argv[1]);

	parser parser{ tokens };

	try
	{
		auto program = parser.buildProgram();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}