#include "Expression.h"
#include<string>

template <typename T>
Expression<T>::Expression(int linesNumber, T v) : Token{ linesNumber }, value { v }
{
}

Expression<int>::Expression(int linesNumber, int v) : Token{ linesNumber }, value{ v }
{
}

Expression<bool>::Expression(int linesNumber, bool v) : Token{ linesNumber }, value{ v }
{
}
Expression<std::string>::Expression(int linesNumber, std::string v) : Token{ linesNumber }, value{ v }
{
}
Expression<char>::Expression(int linesNumber, char v) : Token{ linesNumber }, value{ v }
{
}
