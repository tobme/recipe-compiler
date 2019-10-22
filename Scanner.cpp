#include "Scanner.h"
#include<fstream>
#include<iostream>
#include "Tokens/Int.h"
#include "Tokens/Char.h"
#include "Tokens/String.h"
#include "Tokens/Bool.h"
#include "Tokens/Names.h"



Scanner::Scanner() : linesNumber{0}
{
}


Scanner::~Scanner()
{
}

std::vector<Token*> Scanner::read(std::string filename)
{
	std::vector<Token*> tokens;

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
			tokens.push_back(new Int(linesNumber));
		}
		else if (text == "2dl")
		{
			tokens.push_back(new Char(linesNumber));
		}
		else if (text == "3dl")
		{
			tokens.push_back(new String(linesNumber));
		}
		else if (text == "4dl")
		{
			tokens.push_back(new Bool(linesNumber));
		}
		else
		{
			tokens.push_back(new Names(text, linesNumber));
		}

		if (readStream.peek() == '\n')
		{
			linesNumber++;
		}
	}



	return tokens;
}
