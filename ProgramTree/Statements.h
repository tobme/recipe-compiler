#pragma once
#include "Node.h"
class Statements :
	public Node
{
public:
	Statements();
	virtual ~Statements();
	virtual std::ostream& codegen(std::ostream& os) = 0;
};

