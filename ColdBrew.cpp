#include "ColdBrew.h"


/**
 * default constructor for ColdBrew.
 * 
 */
ColdBrew::ColdBrew() 
{
	
}


/**
 * constructor with parameters for ColdBrew.
 * 
 * \param topping - can be vanilla, chocolate or caramel
 * \param hasMilk - true - cold brew has milk, false otherwise
 */
ColdBrew::ColdBrew(string topping, bool hasMilk)
{
	this->topping = topping;
	this->hasMilk = hasMilk;
	this->coffeeTypes = coldBrew;
}


/**
 * default destructor for ColdBrew.
 * 
 */
ColdBrew::~ColdBrew()
{
}


/**
 * setter for hasMilk.
 * 
 * \param hasMilk - true - cold brew has milk, false otherwise
 */
void ColdBrew::setHasMilk(bool hasMilk)
{
	this->hasMilk = hasMilk;
}


/**
 * setter for topping.
 * 
 * \param topping - can be vanilla, chocolate or caramel
 */
void ColdBrew::setTopping(string topping)
{
	this->topping = topping;
}


/**
 * getter for hasMilk.
 * 
 * \returns  true if cold brew has milk, false otherwise
 */
bool ColdBrew::getHasMilk() const
{
	return this->hasMilk;
}


/**
 * getter for topping.
 * 
 * \returns topping
 */
string ColdBrew::getTopping() const
{
	return this->topping;
}



/**
 * displays ColdBrew order.
 * 
 */
void ColdBrew::display()
{
	Customer::display();
	if (hasMilk == true) {
		cout << left << setw(10) << "This customer's order is : Cold Brew " <<setw(10) << " topping : " << setw(10) << topping << setw(10) << " with milk : yes " << endl;
	}
	else if (hasMilk == false) {
		cout << left << setw(10) << "This customer's order is : Cold Brew " << setw(10) << " topping : " << setw(10) << topping << setw(10) << " with milk : no " << endl;
	}
}

