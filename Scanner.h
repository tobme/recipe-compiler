#pragma once
#include<list>
#include "Tokens/Token.h"
#include<string>
#include<array>
#include<vector>

class Scanner
{
public:
	Scanner();
	~Scanner();

	std::vector<Token> read(std::string filename);
private:
	int linesNumber;
};

