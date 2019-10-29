#include "TokFunctions.h"



TokFunctions::TokFunctions(int lineNumber, std::string const& n) : Token{lineNumber}, name{n}
{
}


TokFunctions::~TokFunctions()
{
}

std::string TokFunctions::getName()
{
	return name;
}
