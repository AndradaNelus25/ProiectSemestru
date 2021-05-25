#pragma once
#include "Customer.h"
#include <iostream>
using namespace std;

enum OperationType {add, Remove, update};

class Operations
{
	Customer* element;
	OperationType op;

public:
	Operations(Customer* element, OperationType op);
	~Operations();
	OperationType getType() const;
	Customer* getCustomer() const;
};

