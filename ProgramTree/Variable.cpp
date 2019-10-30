#include "Variable.h"



Variable::Variable(std::string const& n) : name{ n }
{
}


Variable::~Variable()
{
}

std::ostream& Variable::codegen(std::ostream& os)
{
	os << "[" << name << "]";

	return os;
}
std::string Variable::getName() { return "[" + name + "]"; }