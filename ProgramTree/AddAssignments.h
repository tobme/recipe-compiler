#pragma once
#include "Node.h"
#include "Type.h"
#include "Assignment.h"
#include "../Tokens/Expression.h"

class AddAssignment :
	public Assignment
{
public:
	AddAssignment(ParsExpression* e, Variable* v);
private:

};

