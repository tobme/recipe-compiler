#pragma once
#include "Expression.h"
class Numeral :
	public Expression<int>
{
public:
	Numeral(int line, int value);
};

