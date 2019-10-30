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

	os << "section .bss" << std::endl;

	for (Declaration* decl : decls) // Generate code for all the declarations
	{
		decl->codegen(os);
	}

	os << std::endl;

	os << "\textern  _GetStdHandle@4" << std::endl;
	os << "\textern  _WriteFile@20" << std::endl;
	os << "\textern  _ExitProcess@4" << std::endl;

	os << "section .text" << std::endl;
	os << "\t" << "global _main" << std::endl;

	os << std::endl;


	for (Functions* func : funcs) // Generate code for all the functions
	{
		func->codegen(os);
	}
	
	/*
	* Standard implementation for Print
	*
	*/
	os << "Print:" << std::endl;
	os << "\tmov\t" << "ebp, esp" << std::endl;
	os << "\tsub\t" << "esp, 4" << std::endl;
	os << std::endl;

	os << "\tpush\t" << "-11" << std::endl;
	os << "\tcall\t" << "_GetStdHandle@4" << std::endl;
	os << "\tmov\t" << "ebx, eax" << std::endl;
	os << std::endl;

	os << "\tpush\t" << "0" << std::endl;
	os << "\tlea\t" << "eax, [ebp - 4]" << std::endl;
	os << "\tpush\t" << "eax" << std::endl;
	os << "\tpush(message_end - message)" << std::endl;
	os << "\tpush\t" << "message" << std::endl;
	os << "\tpush\t" << "ebx" << std::endl;
	os << "\tcall\t"<< "_WriteFile@20" << std::endl;
	os << std::endl;

	os << "\tpush\t" << "0" << std::endl;
	os << "\tpush\t" << "_ExitProcess@4" << std::endl;


	return os;
}