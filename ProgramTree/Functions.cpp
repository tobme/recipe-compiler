#include "Functions.h"



Functions::Functions(std::vector<Statements*> state, std::string n) : statements{ state }, name{ n }
{
	if (name == "Directions")
		name = "_main";

}


Functions::~Functions()
{
	for (Statements* statement : statements)
		delete(statement);
}

std::ofstream& Functions::codegen(std::ofstream& os)
{

	os << name << ':' << std::endl;

	for (Statements* statement : statements)
		statement->codegen(os);

	return os;
}
