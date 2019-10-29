#include "Functions.h"



Functions::Functions(std::vector<Statements*> state, std::string n) : statements{ state }, name{ n }
{
}


Functions::~Functions()
{
	for (Statements* statement : statements)
		delete(statement);
}

std::ofstream& Functions::codegen(std::ofstream& os)
{
	/* TODO */

	return os;
}
