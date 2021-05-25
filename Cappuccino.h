#pragma once
#include <iostream>
using namespace std;
#include "Customer.h"

class Cappuccino : public Customer
{
protected:
	string size; // size of cappuccino : can be small, medium, large
	bool isIced; // true - cappuccino has ice ; false - cappuccino doesn't have ice


public:
	//constructors
	Cappuccino(); //default constructor
	Cappuccino(string size, bool isIced); //constructor with parameters

	//destructor
	~Cappuccino();
	
	//setters
	void setSize(string size);
	void setIsIced(bool isIced);

	//getters
	string getSize() const;
	bool getIsIced() const;

	//display
	void display();
	 

};

