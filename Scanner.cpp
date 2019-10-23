#include "Scanner.h"
#include<fstream>
#include<iostream>
#include "Tokens/Int.h"
#include "Tokens/Char.h"
#include "Tokens/String.h"
#include "Tokens/Bool.h"
#include "Tokens/Names.h"
#include "Tokens/EndCode.h"
#include "Tokens/StartCode.h"



Scanner::Scanner() : linesNumber{ 2 }, tokens{}
{
}


Scanner::~Scanner()
{
	for (Token* t : tokens)
	{
		free(t);
	}
}

std::vector<Token*>& Scanner::read(std::string filename)
{

	std::ifstream readStream{ filename };
	std::string text = "";
	char c = {};

	if (!readStream.is_open())
	{
		std::cout << "Could not open file" << std::endl;
		return tokens;
	}

	getline(readStream, text); // Title
	text = "";

	while (readStream.get(c))
	{
		//c = readStream.get();
		if (c != ' ' && c!= '\n')
			text += c;



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
		else if (text == "Enjoy")
		{
			tokens.push_back(new EndCode(linesNumber));
		}
		else if (text == "Begin")
		{
			tokens.push_back(new StartCode(linesNumber));
		}
		else if ((readStream.peek() == '\n' || readStream.peek() == ' ') && text != "")
		{
			tokens.push_back(new Names(text, linesNumber));
		}

		if (readStream.peek() == ' ' || readStream.peek() == '\n')
		{
			std::cout << "Print text: " << text << std::endl;
			std::cout << "line Number: " << linesNumber << std::endl;
			text = "";
		}

		if (c == '\n' || c == '\r')
		{
			linesNumber++;
		}
	}

	readStream.close();

	return tokens;
}
