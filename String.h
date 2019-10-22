#pragma once
#include "Token.h"
class String :
	public Token
{
public:
	using Token::Token;
	~String();
};

