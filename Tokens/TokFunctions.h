#pragma once
#include "Token.h"
#include<string>
class TokFunctions :
	public Token
{
public:
	TokFunctions(int lineNumber, std::string const& n);
	~TokFunctions();
	std::string getName();
private:
	std::string name;
};

