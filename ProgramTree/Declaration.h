#pragma once
#include<string>
#include "Node.h"
#include "Type.h"
class Declaration :
	public Node
{
public:
	Declaration(std::string n, Type t);
	~Declaration();
private:
	std::string name;
	Type type;
};

