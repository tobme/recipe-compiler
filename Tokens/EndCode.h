#pragma once
#include "Token.h"
class EndCode :
	public Token
{
public:
	using Token::Token;
	~EndCode();
};

