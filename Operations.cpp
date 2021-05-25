#include "Operations.h"

Operations::Operations(Customer* element, OperationType op)
{
	this->element = element;
	this->op = op;
}

Operations::~Operations()
{
}

OperationType Operations::getType() const
{
	return this->op;
}

Customer* Operations::getCustomer() const
{
	return element;
}


