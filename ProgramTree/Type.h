#pragma once
#include "Node.h"
#include<string>
class Type :
	public Node
{
public:
	Type(std::string t);
	~Type();
	unsigned getSize();
private:
	std::string type;
};

