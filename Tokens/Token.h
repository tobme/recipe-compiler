#pragma once
class Token
{
public:
	Token(int num);
	virtual ~Token();
	int getLine() { return lineNumber; }
private:
	int lineNumber;
};

