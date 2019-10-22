#pragma once
#include "Node.h"
#include "Declaration.h"
#include<list>
class Program :
	public Node
{
public:
	Program(std::list<Declaration*> & decl);
	~Program();
private:
	std::list<Declaration*> & decls;
};

