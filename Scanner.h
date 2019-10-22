#pragma once
#include<list>
#include "Token.h"
#include<string>
#include<array>

class Scanner
{
public:
	Scanner();
	~Scanner();

	std::list<Token> read(std::string filename);
private:
	int linesNumber;
};

