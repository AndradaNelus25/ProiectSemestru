#pragma once
#include "Controller.h"
#include <iostream>
using namespace std;

class UI
{
private:
	void showMenu();
	Controller* ctrl;

public:
	UI();
	~UI();

	void run();

	void addCustomer();

	void removeCustomer();
	void removeCustomerByName();

	void filterCappucino();
	void filterColdBrew();

	void updateCustomer();
	void searchByName();
	void searchByID();

	vector<Customer*> getAll();

	void undo();
	void redo();

	

};

