#include "testStock.hpp"
void testConstructorSystem()
{
	System* m = System::createSystem();
	Stock* x = m->createStock(10, "MY Stock");

	assert(10 == x->getEnergy());
	cout<<"Constructor are working for energy"<<endl;

	assert("MY Stock" == x->GetLabel());
	cout<<"constructor are working for label"<<endl;
	assert(System::deleteSystem(m));
}
void testSetGetSystem()
{	System* m = System::createSystem();
	Stock* aux = m->createStock();
	aux->setLabel("MY Stock");
	aux->setEnergy(100);


	assert(aux->GetLabel() == "MY Stock");
	cout << "Get and Set Label are working" << endl;

	assert(aux->getEnergy() == 100);
	cout << "Get and Set Energy are working" << endl;
	assert(System::deleteSystem(m));
}
void testingOverload()
{
	System* m = System::createSystem();
	Stock* x = m->createStock(10, "mySistem");
	Stock* y = x;
	assert(x->GetLabel() == y->GetLabel());
	cout<<"The overlflow of = are working"<<endl;
	assert(System::deleteSystem(m));
}




void testingSystem(){

	testConstructorSystem();
	testSetGetSystem();
	testingOverload();

}