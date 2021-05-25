#pragma once
#include "Cappuccino.h"
#include "ColdBrew.h"
#include "Customer.h"
#include "Controller.h"
#include <iostream>
#include <assert.h>
using namespace std;

class Tests
{
public:
	void testCustomer();
	void testCappuccino();
	void testColdBrew();
	void testOperations();
	void testRepository();
	void testController();
	void StartTests();
};

