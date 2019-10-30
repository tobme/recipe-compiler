#pragma once
#include "Node.h"
#include<string>

class MyOperator :
	public Node
{
public:
	MyOperator(std::string n);
	std::string getName();
private:
	std::string name;
};

