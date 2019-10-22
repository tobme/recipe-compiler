#pragma once
#include "Token.h"
#include<string>
class Names :
	public Token
{
public:
	Names(std::string n, int num);
	~Names();
	std::string getName()
	{
		return name;
	}
private:
	std::string name;
};

