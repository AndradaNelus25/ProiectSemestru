#include "Customer.h"

//int Customer::contor = 0;

/** default constructor for Customer */
Customer::Customer()
{
}


/**
 * constructer with parameters for Customer instance
 *
 * 
 * \param orderID - the orderID for a Customer
 * \param name - the name of the Customer
 * \param coffeeType - the coffee type wanted by the Customer
 */
Customer::Customer(int orderID, string name, Coffee coffeeType)
{
	this->orderID = orderID;
	this->name = name;
	this->coffeeTypes = coffeeType;
}


/**
 * copy constructor for Customer.
 * 
 * \param other - Customer type
 */
Customer::Customer(const Customer& other)
{
	this->name = other.name;
	this->coffeeTypes = other.coffeeTypes;
	this->orderID = other.orderID;
}


/**
 * assignment operator for Customer.
 * 
 * \param other - Customer
 * \return 
 */
Customer& Customer::operator=(const Customer& other)
{
	if (this != &other) {
		this->name = other.name;
		this->coffeeTypes = other.coffeeTypes;
		this->orderID = other.orderID;
	}
	else {

	}
	return *this;
}


/**
 * setter for orderID.
 * 
 * \param orderID - the orderID for a Customer
 */
void Customer::setOrderId(int orderID)
{
	this->orderID = orderID;
}


/**
 * setter for customer name.
 * 
 * \param name - the name of the Customer
 */
void Customer::setName(string name)
{
	this->name = name;
}


/**
 * setter for coffee type
 * 
 * \param coffeeType - the coffee type wanted by the Customer
 */
void Customer::setCoffeeType(Coffee coffeeType)
{
	this->coffeeTypes = coffeeType;
}


/** getter for orderID */
int Customer::getOrderID() const
{
	return orderID;
}


/** getter for customer name */
string Customer::getName() const
{
	return this->name;
}

/** getter for coffee type */
Coffee Customer::getCoffeeType() const
{
	return this->coffeeTypes;
}

/* display function for Customer */
void Customer::display()
{
	cout << left << "Customer : " << setw(10) << name << setw(10) << " has order number : " << setw(10) << to_string(orderID) << setw(10);
}

/** default destructor */
Customer::~Customer()
{
	
}



