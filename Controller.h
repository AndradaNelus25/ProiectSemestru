#pragma once
#include <string>
#include "Repository.h"
#include <iostream>
using namespace std;

class Controller
{
	Repository repo; //Repository

public:
	// constructor
	Controller(); 

	//destructor
	~Controller();

	//void addCappuccino(int orderID, string name, int coffeeType, string size, string topping);
	//void addColdBrew(int orderID, string name, int coffeeType, string size, string topping);
	
	vector<Customer*> getAll();

	void undo();
	void redo();

	void add(Customer* c);

	bool removeByName(string name);
	bool removeByOrderID(int orderID);

	//void updateCustomer(Customer* c);

	
	void filter_ColdBrew();
	void filterCappuccino();

	Customer getCustomerByName(string name);
	Customer getCustomerByOrderID(int orderID);

	void searchByName(string name);
	void searchByOrderID(int orderID);

	void displayCustomer();

	int Size();
};

