#pragma once
#include "Node.h"
#include<vector>
#include "Statements.h"

class Functions :
	public Node
{
public:
	Functions(std::vector<Statements*> state, std::string n);
	~Functions();
	std::ofstream& codegen(std::ofstream& os);
private:
	std::vector<Statements*> statements;
	std::string name;
};

