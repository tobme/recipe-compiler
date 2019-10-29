#pragma once
#include<list>
#include "Tokens/Token.h"
#include "ProgramTree/Declaration.h"
#include "ProgramTree/Program.h"
#include "ProgramTree/Assignment.h"
#include "ProgramTree/myOperator.h"
#include "ProgramTree/Functions.h"
#include<vector>

class parser
{
public:
	parser(std::vector<Token*> & t);
	~parser();
	Program* buildProgram();
private:
	std::vector<Token*> token;


	Declaration* buildDeclaration();
	Assignment* buildAssignment();
	MyOperator* buildOperator();
	ParsExpression* buildExpression();
	Functions* buildFunctions();
	Type* buildType();
	Statements* buildStatements();
};

