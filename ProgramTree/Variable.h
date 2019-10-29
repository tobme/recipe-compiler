#pragma once
#include "ParsExpression.h"
#include<string>

class Variable :
	public ParsExpression
{
public:
	Variable(std::string const & n);
	~Variable();
private:
	std::string name;
};

