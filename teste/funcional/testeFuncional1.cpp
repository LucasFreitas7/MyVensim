#include "testeFuncional1.hpp"
#define DEBUGING
int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;

class Myflow2: public FlowHandle{
    public:
    //!Equation
    float equation() /*!< equation of the exponential case*/
    {	float aux = 0.01 * this->getTarget()->getEnergy();
    	float aux2 = 1 -(this->getTarget()->getEnergy()/70);
    	float aux3 = aux * aux2;
    	return aux3;

   	}
   
 };

void logistics()
{
	System* m1 = System::createSystem();
	System *m =  System::createSystem();

	Flow *p1 = m->createFlow<Myflow2>();
	Stock *x = m->createStock(100, "p1");
	Stock *y =  m->createStock(10, "p2");
	
	p1->connect(x, y);
	
	
	m1->executeSubSystems(0, 100, m);
	
	
	float x1 = fabs(88.2167 - x->getEnergy());
	float x2 = fabs(21.7833 - y->getEnergy());
	assert( x1 < 0.0001);
	assert( x2 < 0.0001);
	cout << x->getEnergy() << endl;
	cout << y->getEnergy() << endl;
	assert(System::deleteSystem(m));
	 /*!< Simulating logistics, second System in example */
	//delete(myFlow2) p1;
	//delete x;
	//delete y;
	//delete m;
	
}