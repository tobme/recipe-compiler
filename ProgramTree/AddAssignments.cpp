#include "AddAssignments.h"


AddAssignment::AddAssignment(ParsExpression* e, Variable* v) : Assignment{ new MyOperator{"Add"}, e, v }
{
}

