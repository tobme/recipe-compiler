#include "ParsNumeral.h"
#include<string>


ParsNumeral::ParsNumeral(int v) : value{ v }
{
}


ParsNumeral::~ParsNumeral()
{
}

std::ostream& ParsNumeral::codegen(std::ostream& os)
{
	os << value;

	return os;
}
std::string ParsNumeral::getName() { return std::to_string(value); }