#pragma once
#include <iostream>
using namespace std;
#include "Customer.h"

class ColdBrew : public Customer

{
protected:
	string topping; // topping of cold brew : can be vanilla, chocolate or caramel
	bool hasMilk; // is true - cold brew has milk, false otherwise

	

public:
	//constructors
	ColdBrew(); // default constructor
	ColdBrew(string topping, bool hasMilk); // constructor with parameters

	//destructor
	~ColdBrew();

	//setters
	void setHasMilk(bool hasMilk);
	void setTopping(string topping);

	//getters
	bool getHasMilk() const;
	string getTopping() const;

	//display
	void display();

};

