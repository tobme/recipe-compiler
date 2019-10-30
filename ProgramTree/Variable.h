#pragma once
#include "ParsExpression.h"
#include<string>

class Variable :
	public ParsExpression
{
public:
	Variable(std::string const & n);
	~Variable();
	std::ostream& codegen(std::ostream& os) override;
	std::string getName() override;
private:
	std::string name;
};

