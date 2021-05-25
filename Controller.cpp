#include "Controller.h"
#include "Cappuccino.h"
#include "Customer.h"
#include "ColdBrew.h"


/**
 * default constructor for Controller.
 * 
 */
Controller::Controller()
{
	//this->repo = new Repository();
}


/**
 * default destructor for Controller.
 * 
 */
Controller::~Controller()
{
}

/*void Controller::addCappuccino(int orderID, string name, int coffeeType, string size, string topping)
{
	Coffee newCoffee = (Coffee)coffeeType;
	Customer* cappuccino = new Cappuccino(newCoffee, name, size, topping);
	cappuccino->setOrderId(Customer::contor);
	Customer::contor += 1;

	this->repo.add(cappuccino);
}

void Controller::addColdBrew(int orderID, string name, int coffeeType, string size, string topping)
{
	Coffee coffee = (Coffee)coffeeType;
	Customer* coldBrew = new ColdBrew(coffee, name, size, topping);
	coldBrew->setOrderId(Customer::contor);
	Customer::contor += 1;

	this->repo.add(coldBrew); 
}
*/

/**
 * returns all data in Repository.
 * 
 * \return 
 */
vector<Customer*> Controller::getAll()
{
	return this->repo.getAll();
}


/**
 * undo function.
 * 
 */
void Controller::undo()
{
	this->repo.undo();
}


/**
 * redo function.
 * 
 */
void Controller::redo()
{
	this->repo.redo();
}

void Controller::add(Customer* c)
{
	return this->repo.add(c);
}

bool Controller::removeByName(string name)
{
	return this->repo.removeByName(name);
}

bool Controller::removeByOrderID(int orderID)
{
	return this->repo.removeByOrderID(orderID);
}

/*void Controller::updateCustomer(Customer* c)
{
	this->repo.updateCustomer(c);
}
*/


void Controller::filter_ColdBrew()
{
	bool ok = false;

	auto lambda = [&](Customer customer) {
		if (customer.getCoffeeType() == coldBrew) {
			ok = true;
			customer.display();
			cout << endl;
		}
	};

	vector<Customer> customers;
	for (int i = 0; i < this->repo.RepoSize(); i++) {
		customers.push_back(*this->repo.getAll()[i]);
	}

	this->repo.filter(customers, lambda);

	if (ok == false)
		cout << "No one ordered cold brew \n";
}

void Controller::filterCappuccino()
{
	bool ok = false;

	auto lambda = [&](Customer customer) {
		if (customer.getCoffeeType() == cappuccino) {
			ok = true;
			customer.display();
			cout << endl;
		}
	};

	vector<Customer> customers;
	for (int i = 0; i < this->repo.RepoSize(); i++) {
		customers.push_back(*this->repo.getAll()[i]);
	}

	this->repo.filter(customers, lambda);

	if (ok == false)
		cout << "No one ordered cappuccino \n";
}

Customer Controller::getCustomerByName(string name)
{
	return this->repo.getCustomerByName(name);
}

Customer Controller::getCustomerByOrderID(int orderID)
{
	return this->repo.getCustomerByOrderID(orderID);
}

void Controller::searchByName(string name)
{
	return this->repo.searchByName(name);
}

void Controller::searchByOrderID(int orderID)
{
	return this->repo.searchByOrderID(orderID);
}

void Controller::displayCustomer()
{
	this->repo.displayCustomer();
}

int Controller::Size()
{
	return this->repo.RepoSize();
}

