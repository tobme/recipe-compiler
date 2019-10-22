#pragma once
#include "Node.h"
#include<string>
class Type :
	public Node
{
public:
	Type(std::string t);
	~Type();
private:
	std::string type;
};

