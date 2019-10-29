#pragma once
#include<string>
#include "Node.h"
#include "Type.h"
#include<unordered_map>

class Declaration :
	public Node
{
public:
	Declaration(std::string n, Type* t);
	~Declaration();
	std::ofstream& codegen(std::ofstream& os);
private:
	std::string name;
	Type* type;
};

