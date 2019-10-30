#pragma once

#include "Node.h"

class ParsExpression :
	public Node
{
public:
	ParsExpression();
	virtual ~ParsExpression();
	virtual std::ostream& codegen(std::ostream& os) = 0;
	virtual std::string getName() = 0;
};

