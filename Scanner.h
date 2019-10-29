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

	std::vector<Token*>& read(std::string filename);
private:
	bool is_number(std::string const& s);

	int linesNumber;
	std::vector<Token*> tokens;
};

