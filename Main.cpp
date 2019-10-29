#include <string>
#include "Scanner.h"
#include<vector>
#include "parser.h"
#include<iostream>
#include <fstream>
#include<sstream>

int main(int argc, char* argv[])
{

	Scanner scanner{};

	auto tokens = scanner.read(argv[1]);

	parser parser{ tokens };
	Program* program = nullptr;

	try
	{
		program = parser.buildProgram();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::ofstream os{ "test.asm" };

	if (!os)
	{
		std::cout << "Cannot open file" << std::endl;
		return 1;
	}

	program->codegen(os);

	os.close();

	return 0;
}