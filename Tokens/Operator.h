#pragma once
#include "Token.h"
class Operator :
	public Token
{
public:
	using Token::Token;
	~Operator();
};

