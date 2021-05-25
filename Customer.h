#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// enum for coffe types
enum Coffee {coldBrew, cappuccino};

class Customer
{

protected:
	int orderID; // orderID for orders, unique
	string name; // name of the customer
	Coffee coffeeTypes; // coffee type ordered by the customer
	

public:

	//constructors
	Customer(); //default constructor
	Customer(int orderID, string name, Coffee coffeeType); //constructor with parameters
	Customer(const Customer& other); // copy constructor
	Customer& operator=(const Customer& other); // assignment operator

	//setters
	void setOrderId(int orderID);
	void setName(string name);
	void setCoffeeType(Coffee coffeeType);

	//getters
	int getOrderID() const;
	string getName() const;
	Coffee getCoffeeType() const;

	//display function
	virtual void display();

	//destructors
	virtual ~Customer();




};

