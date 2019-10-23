#include "parser.h"
#include<typeinfo>
#include "Tokens/Names.h"
#include "Tokens/String.h"
#include "Tokens/Int.h"
#include "Tokens/Char.h"
#include "Tokens/Bool.h"
#include "Tokens/StartCode.h"
#include "Tokens/EndCode.h"
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

	while (true) // Building declarations
	{
		if (token.empty())
			break;


		type = buildType();

		if (type == nullptr)
			break;

		decl = buildDeclaration();
		tempDecl.push_back(decl);
	}

	
	if (dynamic_cast<StartCode*>(token.front()))
	{
		token.erase(token.begin());
	}
	else
	{
		std::string temp = "Compile error at line: " + std::to_string(token.front()->getLine()) + " : Expected Begin";
		throw std::exception(temp.c_str());
	}

	/*
	* Program code start
	*/




	/*
	* Program Code ends
	*/

	if (dynamic_cast<EndCode*>(token.front()))
	{
		token.erase(token.begin());
	}
	else
	{
		std::string temp = "Compile error at line: " + std::to_string(token.front()->getLine()) + " : Expected Enjoy";
		throw std::exception(temp.c_str());
	}


	if (!token.empty())
	{

		std::string temp = "Compile error at line: " + std::to_string(token.front()->getLine());
		throw std::exception(temp.c_str());
	}

	std::cout << "return program " << std::endl;
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
	std::cout << "Push " << name << std::endl;

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

	return nullptr;
}
