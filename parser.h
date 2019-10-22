#pragma once
#include<list>
#include "Tokens/Token.h"
#include "ProgramTree/Declaration.h"
#include "ProgramTree/Program.h"
#include<vector>

class parser
{
public:
	parser(std::vector<Token> & t);
	~parser();
private:
	std::vector<Token> token;
	Declaration* buildDeclaration();
	Program* buildProgram();
	Type* buildType();
};

