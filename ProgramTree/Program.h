#pragma once
#include "Node.h"
#include "Declaration.h"
#include<list>
#include<sstream>
#include<vector>
#include "Functions.h"

class Program :
	public Node
{
public:
	Program(std::list<Declaration*> decl, std::vector<Functions*> f);
	~Program();
	std::ofstream& codegen(std::ofstream& os);
private:
	std::list<Declaration*> decls;
	std::vector<Functions*> funcs;
};

