#pragma once
#include "Statements.h"
#include "myOperator.h"
#include "ParsExpression.h"
#include "Variable.h"

class Assignment :
	public Statements
{
public:
	Assignment(MyOperator* o, ParsExpression* e, Variable* v);
	virtual ~Assignment();
	std::ostream& codegen(std::ostream& os) override;
private:
	MyOperator* op;
	ParsExpression* exp;
	Variable* reciever;
};

