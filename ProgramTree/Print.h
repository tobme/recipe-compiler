#pragma once
#include "Statements.h"
#include "Variable.h"
class Print :
	public Statements
{
public:
	Print(Variable* v);
	~Print();
	std::ostream& codegen(std::ostream& os) override;
private:
	Variable* var;
};

