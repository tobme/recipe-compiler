#include "parser.h"
#include<typeinfo>
#include "Tokens/Names.h"
#include "Tokens/String.h"
#include "Tokens/Int.h"
#include "Tokens/Char.h"
#include "Tokens/Bool.h"
#include "Tokens/StartCode.h"
#include "Tokens/EndCode.h"
#include "Tokens/Add.h"
#include "Tokens/Expression.h"
#include "Tokens/Numeral.h"
#include "Tokens/TokFunctions.h"
#include "Tokens/TokPrint.h"
#include "Tokens/TokEndNote.h"
#include "ProgramTree/ParsExpression.h"
#include "ProgramTree/ParsNumeral.h"
#include "ProgramTree/Variable.h"
#include "ProgramTree/Functions.h"
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


	auto it = dynamic_cast<TokFunctions*>(token.front());

	if (!(it && it->getName() == "Directions"))
	{
		std::string temp = "Compile error at line: " + std::to_string(token.front()->getLine()) + " : Expected Directions";
		throw std::exception(temp.c_str());
	}


	/*
	* Program code start
	*/

	std::vector<Functions*> tempFuncs = {};

	while (dynamic_cast<TokFunctions*>(token.front()))
	{
		auto func = buildFunctions();
		tempFuncs.push_back(func);
	}




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
	return new Program{tempDecl, tempFuncs};
}

Functions* parser::buildFunctions()
{
	std::string name = dynamic_cast<TokFunctions*>(token.front())->getName();
	token.erase(token.begin());

	std::vector<Statements*> tempStatements = {};

	while (Statements * statement = buildStatements())
	{
		tempStatements.push_back(statement);
	}

	return new Functions{ tempStatements, name };
}
Statements* parser::buildStatements()
{
	if (dynamic_cast<Operator*>(token.front()))
		return buildAssignment();
	else if (dynamic_cast<TokPrint*>(token.front()))
		return buildPrint();

	return nullptr;

}

Print* parser::buildPrint()
{
	token.erase(token.begin()); // Erase Print keyword

	ParsExpression* var = nullptr;

	if (dynamic_cast<Names*>(token.front()))
	{
		var = buildExpression();
	}
	else
	{
		std::string temp = "Compile error at line: " + std::to_string(token.front()->getLine()) + " : Expected a variable name";
		throw std::exception(temp.c_str());
	}

	while (!dynamic_cast<TokEndNote*>(token.front())) // Looking for end note
	{
		token.erase(token.begin());
	}

	token.erase(token.begin());

	return new Print{ dynamic_cast<Variable*>(var) };
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
		std::string temp = "Compile error at line: " + std::to_string(t->getLine()) + " : Expected a variable name";
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

Assignment* parser::buildAssignment()
{
	auto usedOperator = buildOperator();

	// Expected Expression or Names(variable)

	ParsExpression* exp = buildExpression();

	if (exp == nullptr) // Compile error
	{
		std::string temp = "Compile error at line: " + std::to_string(token.front()->getLine()) + " : Expected an expression";
		throw std::exception(temp.c_str());
	}
	std::cout << "Found expression" << std::endl;

	// Remove one free token

	token.erase(token.begin());

	// Expected Names

	Variable* reciever = nullptr;

	if (auto it = dynamic_cast<Names*>(token.front()))
	{
		reciever = new Variable(it->getName());
		token.erase(token.begin());
	}
	else
	{
		std::string temp = "Compile error at line: " + std::to_string(token.front()->getLine()) + " : Expected a variable";
		throw std::exception(temp.c_str());
	}

	return new Assignment{ usedOperator, exp, reciever };

}
MyOperator* parser::buildOperator()
{
	auto t = token.front();
	token.erase(token.begin());

	if (dynamic_cast<Add*>(t))
		return new MyOperator{ "Add" };
	else if (dynamic_cast<Char*>(t))
		return new MyOperator{ "Remove" };
	/*else if (dynamic_cast<Int*>(t)) Added later
		return new Type{ "Int" };
	else if (dynamic_cast<String*>(t))
		return new Type{ "String" };*/

	return nullptr;
}
ParsExpression* parser::buildExpression()
{
	
	auto t = token.front();
	token.erase(token.begin());

	if (auto it = dynamic_cast<Numeral*>(t))
		return new ParsNumeral{ it->value };
	else if (auto it = dynamic_cast<Names*>(t))
		return new Variable{ it->getName() };
	/*else if (dynamic_cast<Int*>(t)) 
		return new Type{ "Int" };
	else if (dynamic_cast<String*>(t))
		return new Type{ "String" };*/
	
	return nullptr;
}
