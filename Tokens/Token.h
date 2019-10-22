#pragma once
class Token
{
public:
	Token(int num);
	virtual ~Token();
private:
	int lineNumber;
};

