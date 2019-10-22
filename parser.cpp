#include "parser.h"
#include<typeinfo>
#include "Tokens/Names.h"


parser::parser(std::vector<Token> & t) : token{t}
{
}


parser::~parser()
{
}

Program* parser::buildProgram()
{
	Declaration* decl = buildDeclaration();
	std::list<Declaration*> tempDecl;
	while ( decl != nullptr)
	{
		tempDecl.push_back(decl);
	}
	return nullptr;
}

Declaration* parser::buildDeclaration()
{
	Token t = token.front();
	Token t2 = token.at(1);

	if (typeid(t) == typeid(Names))
	{
		
	}
	return nullptr;
}

Type* parser::buildType()
{
	return nullptr;
}
