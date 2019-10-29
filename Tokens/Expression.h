#pragma once
#include "Token.h"


template <typename T>
class Expression :
	public Token
{
public:
	Expression<T>(int linesNumber, T v);
	T value;
};
