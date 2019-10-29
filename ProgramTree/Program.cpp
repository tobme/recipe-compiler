#include "Program.h"



Program::Program(std::list<Declaration*> decl, std::vector<Functions*> f) : decls{decl}, funcs{f}
{
}


Program::~Program()
{
	for (Declaration* decl : decls)
		delete(decl);

	for (Functions* func : funcs)
		delete(func);
}


std::ofstream& Program::codegen(std::ofstream& os)
{

	os << "section .text" << std::endl;
	os << "\t" << "global _start" << std::endl;

	os << "section .bss" << std::endl;

	for (Declaration* decl : decls) // Generate code for all the declarations
	{
		decl->codegen(os);
	}

	os << "_start:" << std::endl;

	for (Functions* func : funcs) // Generate code for all the functions
	{
		func->codegen(os);
	}



	return os;
}