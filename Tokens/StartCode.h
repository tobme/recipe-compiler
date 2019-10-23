#pragma once
#include "Token.h"
#include "../ProgramTree/Node.h"
class StartCode :
	public Token, public Node
{
public:
	using Token::Token;
	~StartCode();
};

