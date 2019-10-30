#pragma once
#include "ParsExpression.h"
class ParsNumeral :
	public ParsExpression
{
public:
	ParsNumeral(int v);
	~ParsNumeral();
	std::ostream& codegen(std::ostream& os) override;
	std::string getName() override;
private:
	int value;
};

