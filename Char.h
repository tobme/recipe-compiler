#pragma once
#include "Token.h"
class Char :
	public Token
{
public:

	using Token::Token;
	~Char();
};

