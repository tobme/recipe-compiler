#include "Assignment.h"



Assignment::Assignment(MyOperator* o, ParsExpression* e, Variable* v) : op{ o }, exp{ e }, reciever{ v }
{
}


Assignment::~Assignment()
{
	delete(op);
	delete(exp);
	delete(reciever);
}

std::ostream& Assignment::codegen(std::ostream& os)
{
	std::string opName = op->getName();
	std::string recName = reciever->getName();
	std::string expName = exp->getName();

	os << "\tmov\t" << "eax, " << recName << std::endl;
	os << "\tmov\t" << "ebx, " << expName << std::endl;

	os << "\t" << opName << "\t" << "eax, ebx" << std::endl;

	os << "\tmov\t" << recName << ", " << "eax" << std::endl;

	return os;
}
