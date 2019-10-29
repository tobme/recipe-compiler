#pragma once
#include "ParsExpression.h"
class ParsNumeral :
	public ParsExpression
{
public:
	ParsNumeral(int v);
	~ParsNumeral();
private:
	int value;
};

