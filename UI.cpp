#include "UI.h"
#include <ctype.h>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <cstdlib>


void UI::showMenu()
{
	cout << endl;
	cout << "The MENU is : \n";
	cout << "1. Add customer\n";
	cout << "2. Remove customer by id\n";
	cout << "3. Remove customer by name\n";
	cout << "4. Filter customers\n";
	cout << "5. Search customers\n";
	cout << "6. Print all the customers\n";
	cout << "7. Undo your last action\n";
	cout << "8. Redo your last action\n";
	cout << "0. EXIT \n";
	cout << endl;
}

UI::UI()
{
	this->ctrl = new Controller();
}

UI::~UI()
{
}

void UI::run()
{
	while (true) {
		this->showMenu();
		int op;
		cout << "Enter your option : ";
		while (!(cin >> op)) {
			cout << "Error : Enter an integer for the option : ";
			cin.clear();
			cin.ignore(123, '\n');

		}
		if (op == 1) {
			this->addCustomer();

		}
		else if (op == 2) {
			try {
				this->removeCustomer();
			}
			catch (exception e) {

			}
			}
		else if (op == 3) {
			this->removeCustomerByName();
		}
		else if (op == 4) {
			int option;
			cout << "Choose if you want to get the customers that ordered cappuccino or cold brew : \n";
			cout << "Type \n  1 - for customers that ordered cappuccino\n  2 - for customers that ordered cold brew\n";
			cin >> option;
			if (option == 1) {
				cout << "Customers that want cappuccino : " << endl;
				this->filterCappucino();
			}
			else if (option == 2) {
				cout << "Customers that want cold brew : " << endl;
				this->filterColdBrew();
			}
		}
		else if (op == 5) {
			int option;
			cout << "Choose if you want to get the customers that : \n";
			cout << "Type\n  1 - have a specific name\n  2 - have a specific order id\n";
			cin >> option;
			if (option == 1) {
				this->searchByName();
			}
			else if (option == 2) {
				this->searchByID();
			}
		}
		else if (op == 6) {
			this->ctrl->displayCustomer();
		}
		else if (op == 7) {
			this->undo();
		}
		else if (op == 8) {
			this->redo();
		}
		else if (op == 0) {
			cout << "GOODBYE! \n";
			break;
		}
		else {
			cout << "The option you entered does not exist!";
		}

	}
}



void UI::addCustomer()
{
	int id, coffeeType, size, topping, isIced, hasMilk;
	string name;


	/*cout << "Enter the order id : ";
	try {

		while (!(cin >> id)) {
			cout << "Error : Enter an integer for the orderID : ";
			cin.clear();
			cin.ignore(123, '\n');

		}
	}
	catch (exception e) {
		"The id you entered has to be a positive integer\n";
	}
	*/

	id = rand() % 200;

	cout << "Enter the name of the customer : ";
	cin >> name;
	
	cout << "Enter the order : \n 1 - if the customer wants cappuccino \n 2 - if the customer wants cold brew\n"; 
	cin >> coffeeType;
	
	if (coffeeType == 1) {
		cout << "Enter the size of the coffee : \n  1 - for small \n  2 - for medium \n  3 - for large\n";
		cin >> size;

		cout << "Enter the preference for ice : \n 1 - for yes\n 2 - for no\n";
		cin >> isIced;

		if (size == 1 && isIced == 1)
		{
			Customer* c = new Cappuccino("small", true);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(cappuccino);
			this->ctrl->add(c);
		}
		else if (size == 2 && isIced == 1) {
			Customer* c = new Cappuccino("medium", true);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(cappuccino);
			this->ctrl->add(c);
		}
		else if (size == 3 && isIced == 1)
		{
			Customer* c = new Cappuccino("large", true);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(cappuccino);
			this->ctrl->add(c);
		}
		else if (size == 1 && isIced == 2)
		{
			Customer* c = new Cappuccino("small", false);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(cappuccino);
			this->ctrl->add(c);
		}
		else if (size == 2 && isIced == 2)
		{
			Customer* c = new Cappuccino("medium", false);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(cappuccino);
			this->ctrl->add(c);
		}
		else if (size == 3 && isIced == 2)
		{
			Customer* c = new Cappuccino("large", false);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(cappuccino);
			this->ctrl->add(c);
		}
		else {
			cout << endl;
			cout << "Please enter valid numbers according to the options given! " << endl;
			cout << endl;
		}

	}
	else if (coffeeType == 2) {
		cout << "Enter the topping : \n 1 - for chocolate \n 2 - for vanilla \n 3 - for caramel\n";
		cin >> topping;

		cout << "Enter the preference for milk : \n 1 - for yes \n 2 - for no\n";
		cin >> hasMilk;

		if (topping == 1 && hasMilk == 1)
		{
			Customer* c = new ColdBrew("chocolate", true);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(coldBrew);
			this->ctrl->add(c);
		}
		else if (topping == 2 && hasMilk == 1) {
			Customer* c = new ColdBrew("vanilla", true);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(coldBrew);
			this->ctrl->add(c);
		}
		else if (topping == 3 && hasMilk == 1)
		{
			Customer* c = new ColdBrew("caramel", true);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(coldBrew);
			this->ctrl->add(c);
		}
		else if (topping == 1 && hasMilk == 2)
		{
			Customer* c = new ColdBrew("chocolate", false);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(coldBrew);
			this->ctrl->add(c);
		}
		else if (topping == 2 && hasMilk == 2)
		{
			Customer* c = new ColdBrew("vanilla", false);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(coldBrew);
			this->ctrl->add(c);
		}
		else if (topping == 3 && hasMilk == 2)
		{
			Customer* c = new ColdBrew("caramel", false);
			c->setName(name);
			c->setOrderId(id);
			c->setCoffeeType(coldBrew);
			this->ctrl->add(c);
		}
		else {
			cout << endl;
			cout << "Please enter valid numbers according to the options given! " << endl;
			cout << endl;
		}
	}
	else {
		cout << endl;
		cout << "Please enter valid numbers according to the options given! " << endl;
		cout << endl;
	}
	

}

void UI::removeCustomer()
{
	int id;
	cout << "Enter the order id : ";
	try {

		while (!(cin >> id)) {
			cout << "Error : Enter an integer for the orderID : ";
			cin.clear();
			cin.ignore(123, '\n');

		}
	}
	catch (exception e) {
		"The id you entered has to be a positive integer\n";
	}
	this->ctrl->removeByOrderID(id);
}

void UI::removeCustomerByName()
{
	string name;
	cout << "Enter the name of the customer you want to delete : ";
	cin >> name;
	this->ctrl->removeByName(name);
}

void UI::filterCappucino()
{
	this->ctrl->filterCappuccino();
}

void UI::filterColdBrew()
{
	this->ctrl->filter_ColdBrew();
}

void UI::updateCustomer()
{
	//this->ctrl->updateCustomer(c);
}

void UI::searchByName()
{
	string name;
	cout << "Enter the name of the customer you want to find : ";
	cin >> name;
	this->ctrl->searchByName(name);
}

void UI::searchByID()
{
	int id;
	cout << "Enter the id of the customer you want to find : ";
	cin >> id;
	this->ctrl->searchByOrderID(id);
}

vector<Customer*> UI::getAll()
{
	return this->ctrl->getAll();
}

void UI::undo()
{
	try {
		this->ctrl->undo();
	}
	catch (exception e) {
		"There was an error !";
	}
}

void UI::redo()
{
	try {
		this->ctrl->redo();
	}
	catch (exception e) {
		"There was an error !";
	}
}


