#include"testeFuncional3.hpp"
class Myflow: public FlowHandle{
    public:
        
        //!Equation
        float equation() /*!< equation of the logistic case*/
        {
        	 float aux = (0.01 * this->getSource()->getEnergy());
    		 return aux;
        }
};
void exponential()
{	System* m10 = System::createSystem();
	System *m = System::createSystem();
	Flow *p1 = m->createFlow<Myflow>();
	Stock *x =  m->createStock(100, "pop1");
	Stock *y = m->createStock(0, "pop2");
	
	p1->connect(x, y);
	
	m10->executeSubSystems(0, 100, m);
	float x1 = fabs(36.6032 - x->getEnergy());
	float x2 = fabs(63.3968 -y->getEnergy());
	assert( x1 < 0.0001);
	assert( x2 < 0.0001);
	cout << x->getEnergy() << endl;
	cout << y->getEnergy() << endl;
	assert(System::deleteSystem(m));
	 /*!< Simulating exp, first System in example */
	//delete p1;
	//delete x;
	//delete y;
	//delete m;
		

}