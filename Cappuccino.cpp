#include "Cappuccino.h"

/**
 * default constructor for Cappuccino.
 * 
 */
Cappuccino::Cappuccino()
{
	this->coffeeTypes = cappuccino;
}


/**
 * constructor with parameters for Cappuccino.
 * 
 * \param size - can be small, medium, large
 * \param isIced - true - cappuccino has ice ; false - cappuccino doesn't have ice
 */
Cappuccino::Cappuccino(string size, bool isIced)
{
	this->size = size;
	this->isIced = isIced;
	this->coffeeTypes = cappuccino;
}


/**
 * default destructor.
 * 
 */
Cappuccino::~Cappuccino()
{
}


/**
 * setter for size.
 * 
 * \param size - can be small, medium, large
 */
void Cappuccino::setSize(string size)
{
	this->size = size;
}


/**
 * setter for isIced.
 * 
 * \param isIced - true - cappuccino has ice ; false - cappuccino doesn't have ice
 */
void Cappuccino::setIsIced(bool isIced)
{
	this->isIced = isIced;
}



/**
 * getter for size.
 * 
 * \returns size of drink
 */
string Cappuccino::getSize() const
{
	return this->size;
}


/**
 * getter for isIced.
 * 
 * \returns true if cappuccino is iced, false if it's not
 */
bool Cappuccino::getIsIced() const
{
	return this->isIced;
}



/**
 * displays Cappuccino order.
 * 
 */
void Cappuccino::display()
{
	Customer::display();
	if (isIced == true) {
		cout << left << setw(10) << "This customer's order is : Cappuccino " << setw(10) << "  size : " << setw(10) << size << setw(10) << " with ice : yes " << endl;
	}
	else if(isIced == false){
		cout << left << setw(10) << "This customer's order is : Cappuccino " << setw(10) << "  size : " << setw(10) << size << setw(10) << " with ice : no " << endl;
	}
}

