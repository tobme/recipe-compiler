#include "Declaration.h"



Declaration::Declaration(std::string n, Type* t) : name{n}, type{t}
{
}


Declaration::~Declaration()
{
	free(type);
}
