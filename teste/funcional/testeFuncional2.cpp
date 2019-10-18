#include"testeFuncional2.hpp"
class Myflow: public FlowHandle{
    public:
        
        //!Equation
        float equation() /*!< equation of the logistic case*/
        {
        	 float aux = (0.01 * this->getSource()->getEnergy());
    		 return aux;
        }
};
void Allconected()
{	System* m10 = System::createSystem();
	System* m = System:: createSystem();
	Stock* q1=  m->createStock(100, "q1");
	Stock* q2=  m->createStock(0, "q2");
	Stock* q3=  m->createStock(100, "q3");
	Stock* q4=  m->createStock(0, "q4");
	Stock* q5=  m->createStock(0, "q5");
	Flow *u = m->createFlow<Myflow>();
	Flow *g = m->createFlow<Myflow>();
	Flow *f = m->createFlow<Myflow>();
	Flow *t = m->createFlow<Myflow>();
	Flow *r = m->createFlow<Myflow>();
	Flow *v = m->createFlow<Myflow>();
	v->connect(q4, q1);
	f->connect(q1, q2);
	u->connect(q3, q4);
	t->connect(q2, q3);
	r->connect(q2, q5);
	g->connect(q1, q3);
	
	
	m10->executeSubSystems(0, 100, m);
	float x1 =0, x2=0, x3=0, x4=0, x5=0;
	x1 = fabs(31.8513 - q1->getEnergy());
	x2 = fabs(18.4003 - q2->getEnergy());
	x3 = fabs(77.1143 - q3->getEnergy());
	x4 = fabs(56.1728 - q4->getEnergy());
	x5 = fabs(16.4612 - q5->getEnergy());

	assert( x1 < 0.0001);
	assert( x2 < 0.0001);
	assert( x3 < 0.0001);
	assert( x4 < 0.0001);
	assert( x5 < 0.0001);
	

	cout << q1->getEnergy()<< endl;
	cout << q2->getEnergy() << endl;
	cout << q3->getEnergy() << endl;
	cout << q4->getEnergy() << endl;
	cout << q5->getEnergy() << endl;

	assert(System::deleteSystem(m));
	/*!<simulating the most complex test of the example */
	
	//delete q1;
	//delete q2;
	//delete q3;
	//delete q4;
	//delete q5;
	//delete f;
	//delete v;
	//delete u;
	//delete t;
	//delete r;
	//delete g;
}