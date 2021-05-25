#include "Repository.h"
//#include <qjsondocument.h>
//#include <qjsonobject.h>
//#include <qjsonarray.h>
//#include <qfile.h>
//#include <qstring.h>

/**
 * default constructor for Repository.
 * 
 */
Repository::Repository()
{
	this->jsonFile = "persistance.json";
	this->loadFromJson();
}


/**
 * default destructor for Repository.
 * 
 */
Repository::~Repository()
{
}


/**
 * adds a Customer to repository.
 * 
 * \param customer - Customer instance
 */
void Repository::add(Customer* customer)
{
	if (customer->getOrderID() < 0)
		throw "The orderID has to be a positive number! ";
	this->data.push_back(customer);
	Operations* operation = new Operations(customer, OperationType::add);
	undoStack.push(operation);
	
}


/**
 * removes Customer by name.
 * 
 * \param name - name of the customer to be deleted
 * \returns true if Customer was removed, false otherwise
 */
bool Repository::removeByName(string name)
{
	vector<Customer*>::iterator it;

	bool ok = false;
	for (it = this->data.begin(); it < this->data.end() ; it++) {
		if ((*it)->getName() == name) {
			ok = true;
			Operations* operation = new Operations(*it, OperationType::Remove);
			undoStack.push(operation);
			this->data.erase(it);
			return true;
		}
	}
	if (ok == false)
		cout << "The customer with this name doesn't exist! " << endl;



}


/**
 * removes Customer by orderID.
 * 
 * \param orderID - id of the order 
 * \return true if Customer was removed, false otherwise
 */
bool Repository::removeByOrderID(int orderID)
{
	if (this->data.size() == 0)
		cout << "There is no customer in the repository ! \n";
	else {
		vector<Customer*>::iterator it;
		bool ok = false;
		for (it = this->data.begin(); it < this->data.end(); it++) {
			if ((*it)->getOrderID() == orderID) {
				ok = true;
				Operations* operation = new Operations(*it, OperationType::Remove);
				undoStack.push(operation);
				this->data.erase(it);
				return true;
			}
		}
		if (ok == false)
			cout << "The customer with this order id doesn't exist! " << endl;
			
	}
	
}


/**
 * returns size of Repository.
 * 
 * \return 
 */
int Repository::RepoSize()
{
	return this->data.size();
}


/**
 * returns customers with given name.
 * 
 * \param name - of the customer
 * \return 
 */
Customer Repository::getCustomerByName(string name)
{
	for (int i = 0; i < this->data.size(); i++) {
		if (this->data[i]->getName() == name)
			return *this->data[i];
	}
}


/**
 * returns customers with given orderID.
 * 
 * \param orderID - id of the order of customer
 * \return 
 */
Customer Repository::getCustomerByOrderID(int orderID)
{
	for (int i = 0; i < this->data.size(); i++) {
		if (this->data[i]->getOrderID() == orderID)
			return *this->data[i];
	}
}


/**
 * searches customers with given name.
 * 
 * \param name
 * \return 
 */
void Repository::searchByName(string name)
{
	if (this->data.size() == 0)
	{
		cout << endl;
		cout << "There is no customer in the repository ! \n";
		cout << endl;
	}
	else {
		int i = 0, count = 0;
		while (count < this->data.size()) {
			if (this->data[i]->getName() == name) {
				this->data[i]->display();
				count++;
			}
			i++;
		}
	}
	
			
}


/**
 * searches customers with given order id.
 * 
 * \param orderID
 */
void Repository::searchByOrderID(int orderID)
{
	if (this->data.size() == 0)
	{
		cout << endl;
		cout << "There is no customer in the repository ! \n";
		cout << endl;
	}
	else {
		int i = 0, count = 0;
		while (count < this->data.size()) {
			if (this->data[i]->getOrderID() == orderID) {
				this->data[i]->display();
				count++;
			}
			i++;
		}
	}
}




/**
 * filters Customers with given properties.
 * 
 * \param customers
 * \param func
 */
void Repository::filter(const vector<Customer>& customers, const function<void(Customer)>& func)
{
	if (this->data.size() == 0)
	{
		cout << endl;
		cout << "There is no customer in the repository ! \n";
		cout << endl;
	}
	else {
		for (Customer customer : customers)
			func(customer);
	}
}


//getter
vector<Customer*> Repository::getAll() const
{
	return this->data;
}

/**
 * displays customers in repository.
 * 
 */
void Repository::displayCustomer()
{
	if (this->data.size() == 0) {
		cout << endl;
		cout << "There is no customer in the repository ! \n";
		cout << endl;
	}
	else {
		for (int i = 0; i < this->data.size(); i++) {
			this->data[i]->display();
		}
	}
}


/**
 * undo function.
 * 
 */
void Repository::undo()
{
	if (this->undoStack.size() == 0)
		throw ("Undo operation is not possible ");

	Operations* op = undoStack.top();

	if (op->getType() == OperationType::add) {
		Customer* c = op->getCustomer();

		int index = -1;
		for (int i = 0; i < data.size() and index == -1; i++) {
			if (data[i]->getOrderID() == c->getOrderID())
				index = i;
		}
		data.erase(data.begin() + index);

		Operations* operation = new Operations(op->getCustomer(), OperationType::add);
		redoStack.push(operation);
	}
	else if (op->getType() == OperationType::Remove) {
		Customer* c = op->getCustomer();
		data.push_back(c);

		Operations* operation = new Operations(op->getCustomer(), OperationType::Remove);
		redoStack.push(operation);

	}
	else if (op->getType() == OperationType::update) {
		Customer* c = op->getCustomer();

		vector<Customer*>::iterator it;
		for (it = this->data.begin(); it <= this->data.end(); it++) {
			if (c->getOrderID() == (*it)->getOrderID()) {
				{
					Customer* OldCustomer = *it;
					*it = c;
					Operations* operation = new Operations(OldCustomer, OperationType::update);
					redoStack.push(operation);
				}


			}
		}
	}
	undoStack.pop();
}


/**
 * redo function.
 * 
 */
void Repository::redo()
{
	if (this->redoStack.size() == 0)
		throw ("Redo operation is not possible ");

	Operations* op = redoStack.top();

	if (op->getType() == OperationType::add) {
		Customer* c = op->getCustomer();
		data.push_back(c);
	}
	else if (op->getType() == OperationType::Remove) {
		Customer* c = op->getCustomer();
		int index = -1;

		for (int i = 0; i < data.size() and index == -1; i++) {
			if (data[i]->getOrderID() == c->getOrderID())
				index = i;
		}
		data.erase(data.begin() + index);
	}
	else if (op->getType() == OperationType::update) {
		Customer* c = op->getCustomer();
		vector<Customer*>::iterator it;

		for (it = data.begin(); it <= data.end(); it++) {
			if (c->getOrderID() == (*it)->getOrderID()) {
				{
					*it = c;
				}
			}



		}
	}
	redoStack.pop();
}

/*void Repository::loadFromJson()
{
	QFile persistanceFile(QString::fromStdString(this->jsonFile));
	persistanceFile.open(QFile::ReadOnly);

	QJsonDocument doc = QJsonDocument().fromJson(persistanceFile.readAll());
	QJsonObject rootObject = doc.object();
	QJsonArray rootArray = rootObject.value("customers").toArray();

	for (auto itemObj : rootArray) {
		QJsonObject customerJsonObj = itemObj.toObject();
		int orderID = customerJsonObj.value("id").toInt();
		string name  = customerJsonObj.value("name").toString().toStdString();
		string coffeeType = customerJsonObj.value("coffeeType").toString().toStdString();

		if (coffeeType == "cappuccino") {
			Cappuccino* c = new Cappuccino();
			c->setOrderId(orderID);
			c->setName(name);
			this->add(c);
		}
		else if(coffeeType == "coldBrew"){
			ColdBrew* c = new ColdBrew();
			c->setOrderId(orderID);
			c->setName(name);
			this->add(c);
		}
	}
}

void Repository::saveToJson()
{
	QJsonDocument doc;
	QJsonObject rootObject;
	QJsonArray rootArray;

	for (Customer* customer : this->getAll()) {
		QJsonObject customerObj;
		customerObj.insert("orderID", customer->getOrderID());
		customerObj.insert("name", customer->getName());
		rootArray.push_back(customerObj);
	}

	rootObject.insert("customers", rootArray);
	doc.setObject(rootObject);

	QFile persistenceFile(QString::fromStdString(this->jsonFile));
	persistenceFile.open(QFile::WriteOnly);
	persistenceFile.write(doc.toJson());
	persistenceFile.close();
}

/*void Repository::loadToCsv()
{
	vector<string>customers;
	bool found = false;
	string id, name, coffeeType;
	ifstream f;
	f.open("Load.csv");
	while (getline(f, id, ',') && !found) {
		getline(f, name, ',');
		getline(f, coffeeType, '\n');
		if (coffeeType == "cappuccino") {
			Customer* x = new Cappuccino(string size, bool isIced);
			
			
		}
	}
}
*/


/**


void Repository::updateCustomer(Customer* c, int orderID)
{
	if (this->data.size() == 0)
	{
		cout << endl;
		cout << "There is no customer in the repository ! \n";
		cout << endl;
	}
	else {
		vector<Customer*>::iterator it;
		for (it = this->data.begin(); it <= this->data.end(); it++) {
			if (c->getOrderID() == (*it)->getOrderID()) {
				Operations* operation = new Operations(*it, OperationType::update);
				undoStack.push(operation);
				*it = c;

			}
		}

		throw "The customer doesn't exist";
	}
}
*/