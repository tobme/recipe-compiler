#include "parser.h"
#include<typeinfo>
#include "Tokens/Names.h"
#include "Tokens/String.h"
#include "Tokens/Int.h"
#include "Tokens/Char.h"
#include "Tokens/Bool.h"
#include<exception>
#include<iostream>


parser::parser(std::vector<Token*> & t) : token{t}
{
}


parser::~parser()
{
}

Program* parser::buildProgram()
{
	Declaration* decl = nullptr;
	std::list<Declaration*> tempDecl;
	Type* type = nullptr;

	while (true)
	{
		if (token.empty())
			break;

		try
		{
			type = buildType();
		}
		catch(std::exception)
		{
			break;
		}


		decl = buildDeclaration();
		tempDecl.push_back(decl);

	}

	if (!token.empty())
	{

		std::string temp = "Compile error at line: " + std::to_string(token.front()->getLine());
		throw std::exception(temp.c_str());
	}

	return new Program{tempDecl};
}

Declaration* parser::buildDeclaration()
{
	Type* type = buildType();
	token.erase(token.begin());

	Token* t = token.front();
	std::string name;

	if (dynamic_cast<Names*>(t))
	{
		name = dynamic_cast<Names*>(t)->getName();
		token.erase(token.begin());
	}
	else
	{
		std::string temp = "Compile error at line: " + std::to_string(t->getLine());
		throw std::exception(temp.c_str());
	}

	return new Declaration{ name, type };
}

Type* parser::buildType()
{
	Token* t = token.front();

	if (dynamic_cast<Bool*>(t))
		return new Type{ "Bool" };
	else if (dynamic_cast<Char*>(t))
		return new Type{ "Char" };
	else if (dynamic_cast<Int*>(t))
		return new Type{ "Int" };
	else if (dynamic_cast<String*>(t))
		return new Type{ "String" };
	std::string temp = "Compile error at line: " + std::to_string(t->getLine());
		throw std::exception(temp.c_str());
}
