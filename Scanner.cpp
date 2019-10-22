#include "Scanner.h"
#include<fstream>
#include<iostream>
#include "Int.h"
#include "Char.h"
#include "String.h"
#include "Bool.h"
#include "Names.h"


Scanner::Scanner() : linesNumber{0}
{
}


Scanner::~Scanner()
{
}

std::list<Token> Scanner::read(std::string filename)
{
	std::list<Token> tokens;

	std::ifstream readStream{ filename };
	std::string text;

	if (!readStream.is_open())
	{
		std::cout << "Could not open file" << std::endl;
		return tokens;
	}

	readStream >> text;

	while (readStream >> text)
	{
		std::cout << "Print text: " << text << std::endl;
		std::cout << "line Number: " << linesNumber << std::endl;

		if (text == "1dl")
		{
			tokens.push_back(Int(linesNumber));
		}
		else if (text == "2dl")
		{
			tokens.push_back(Char(linesNumber));
		}
		else if (text == "3dl")
		{
			tokens.push_back(String(linesNumber));
		}
		else if (text == "4dl")
		{
			tokens.push_back(Bool(linesNumber));
		}
		else
		{
			tokens.push_back(Names(text, linesNumber));
		}

		if (readStream.peek() == '\n')
		{
			linesNumber++;
		}
	}



	return std::list<Token>();
}
