#include "Type.h"



Type::Type(std::string t) : type{t}
{
}


Type::~Type()
{
}

unsigned Type::getSize() // Get size in byte
{
	if (type == "Bool" || "Char")
		return 1;
	else
		return 4;
}