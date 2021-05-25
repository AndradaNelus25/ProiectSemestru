#include "Tests.h"


/**
 * tests for constructor, setters and getters of Customer class.
 * 
 */
void Tests::testCustomer()
{
	Customer* c = new Cappuccino("small", true);
	c->setCoffeeType(cappuccino);
	c->setName("Andreea");
	c->setOrderId(33);

	assert("Andreea" == c->getName());
	assert(33 == c->getOrderID());
	assert(cappuccino == c->getCoffeeType());

	Customer* d = new ColdBrew("chocolate", false);
	d->setCoffeeType(coldBrew);
	d->setName("Denis");
	d->setOrderId(4);

	assert("Denis" == d->getName());
	assert(4 == d->getOrderID());
	assert(coldBrew == d->getCoffeeType());
}


/**
 * tests for Cappuccino class.
 * 
 */
void Tests::testCappuccino()
{
	Cappuccino* c = new Cappuccino();
	c->setCoffeeType(cappuccino);
	c->setIsIced(false);
	c->setName("Maria");
	c->setOrderId(16);
	c->setSize("medium");

	assert(cappuccino == c->getCoffeeType());
	assert(false == c->getIsIced());
	assert("Maria" == c->getName());
	assert(16 == c->getOrderID());
	assert("medium" == c->getSize());
}

void Tests::testColdBrew()
{
	ColdBrew* c = new ColdBrew();
	c->setCoffeeType(coldBrew);
	c->setHasMilk(false);
	c->setName("Marius");
	c->setOrderId(63);
	c->setTopping("medium");

	assert(coldBrew == c->getCoffeeType());
	assert(false == c->getHasMilk());
	assert("Marius" == c->getName());
	assert(63 == c->getOrderID());
	assert("medium" == c->getTopping());
}


/**
 * tests for Operations class.
 * 
 */
void Tests::testOperations()
{
	Customer* d = new ColdBrew("chocolate", false);
	Operations* op = new Operations(d, add);
	assert(add == op->getType());
	assert(d == op->getCustomer());

	Operations* op1 = new Operations(d, Remove);
	assert(Remove == op1->getType());
	assert(d == op1->getCustomer());


}


/**
 * tests for Repository class.
 * 
 */
void Tests::testRepository()
{
	Repository* repo = new Repository();
	Customer* d = new ColdBrew("chocolate", false);
	d->setName("Ana");
	d->setOrderId(17);
	
	assert(0 == repo->RepoSize());

	repo->add(d);
	assert(1 == repo->RepoSize());

	repo->removeByOrderID(17);
	assert(0 == repo->RepoSize());

	repo->add(d);
	assert(1 == repo->RepoSize());

	repo->removeByName("Ana");
	assert(0 == repo->RepoSize());

	repo->undo();
	assert(1 == repo->RepoSize());

	repo->redo();
	assert(0 == repo->RepoSize());
}


/**
 * tests for Controller class.
 * 
 */
void Tests::testController()
{
	Controller* ctrl = new Controller();
	Customer* d = new ColdBrew("chocolate", false);
	d->setName("Ana");
	d->setOrderId(17);

	assert(0 == ctrl->Size());

	ctrl->add(d);
	assert(1 == ctrl->Size());

	ctrl->removeByOrderID(17);
	assert(0 == ctrl->Size());

	ctrl->add(d);
	assert(1 == ctrl->Size());

	ctrl->removeByName("Ana");
	assert(0 == ctrl->Size());

	ctrl->undo();
	assert(1 == ctrl->Size());

	ctrl->redo();
	assert(0 == ctrl->Size());

}

void Tests::StartTests()
{
	this->testCappuccino();
	this->testColdBrew();
	this->testController();
	this->testCustomer();
	this->testOperations();
	this->testRepository();
}
