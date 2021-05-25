#pragma once
#include <vector>
#include <stack>
#include "Customer.h"
#include "Cappuccino.h"
#include "ColdBrew.h"
#include "Operations.h"
#include <iostream>
#include <functional>
#include <fstream>
#include <string>
using namespace std;

class Repository
{
private:
	vector<Customer*> data; //vector of Customers 
	stack<Operations*> undoStack; // undo stack for undo function
	stack<Operations*> redoStack; // redo stack for redo function
	string jsonFile;

public:
	//constructor
	Repository();

	//destructor
	~Repository();

	void add(Customer* customer);

	bool removeByName(string name);
	bool removeByOrderID(int orderID);

	int RepoSize();

	Customer getCustomerByName(string name);
	Customer getCustomerByOrderID(int orderID);

	void searchByName(string name);
	void searchByOrderID(int orderID);
	
	void filter(const vector<Customer>& customers, const function<void(Customer)>& func);

	vector<Customer*> getAll() const;

	void displayCustomer();

	void undo();
	void redo();
	
	//void loadToCsv();

	void loadFromJson();
	void saveToJson();
};

