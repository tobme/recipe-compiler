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
