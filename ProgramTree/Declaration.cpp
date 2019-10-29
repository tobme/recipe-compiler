#include "Declaration.h"



Declaration::Declaration(std::string n, Type* t) : name{n}, type{t}
{
	
}


Declaration::~Declaration()
{
	//free(type);
}
std::ofstream& Declaration::codegen(std::ofstream& os)
{
	int byteSize = type->getSize();

	os << "\t" <<  name << "\t" << "RESB" << "\t" << byteSize << std::endl;

	return os;
}