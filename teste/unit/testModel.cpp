#include "testModel.hpp"
int numHandleCreated=0;
int numHandleDeleted=0;
int numBodyCreated=0;
int numBodyDeleted=0;
class Myflow: public FlowHandle{
    public:
        
        //!Equation
        float equation() /*!< equation of the logistic case*/
        {
        	 float aux = (0.01 * this->getSource()->getEnergy());
    		 return aux;
        }
};

void testConstructorModel()
{
	System* m = System::createSystem();
	Stock* s1 = m->createStock(100, "q1");
	Flow* f1 = m->createFlow<Myflow>();
	f1->setName("fluxo1");

	assert(f1->getName() == "fluxo1");
	cout<<"the contructor is working correctly"<<endl;

	assert(s1->GetLabel() == "q1");
	cout<<" the constructor is working correctly for label Stock"<<endl;

	assert(s1->getEnergy() == 100);
	cout<<"the constructor is working correctly for energy Stock"<<endl;
	assert(System::deleteSystem(m));
	//delete s1;
	//delete f1;
}
void testingAddFlow()
{
	System* m = System::createSystem();
	Flow* f1 = m->createFlow<Myflow>();
	f1->setName("fluxo1");
	Flow* f2 = m->createFlow<Myflow>();
	f2->setName("fluxo2");
	Flow* f3 = m->createFlow<Myflow>();
	f3->setName("fluxo3");
	Flow* f4 = m->createFlow<Myflow>();
	f4->setName("fluxo4");
	Flow* f5 = m->createFlow<Myflow>();
	f5->setName("fluxo5");
	Flow* f6 = m->createFlow<Myflow>();
	f6->setName("fluxo6");


	
	
	
	///cout<<m->getFlow(5)->getName()<<endl;
	assert(m->getFlow(5)->getName() == "fluxo6");
	assert(m->getFlow(4)->getName() == "fluxo5");
	assert(m->getFlow(3)->getName() == "fluxo4");
	assert(m->getFlow(2)->getName() == "fluxo3");
	assert(m->getFlow(1)->getName() == "fluxo2");
	assert(m->getFlow(0)->getName() == "fluxo1");

	cout<<"add flow to vector is working correctly"<<endl;
	assert(System::deleteSystem(m));
	//delete f1;
	//delete f2;
	//delete f3;
	//delete f4;
	//delete f5;
	//delete f6;



}
void testingAddSystem(){
	System* m = System::createSystem();
	Stock* q1=  m->createStock(100, "q1");
	Stock* q2=  m->createStock(0, "q2");
	Stock* q3=  m->createStock(100, "q3");
	Stock* q4=  m->createStock(0, "q4");
	Stock* q5=  m->createStock(0, "q5");
	
	
	assert(m->getStock(0)->GetLabel() == "q1");
	assert(m->getStock(1)->GetLabel() == "q2");
	assert(m->getStock(2)->GetLabel() == "q3");
	assert(m->getStock(3)->GetLabel() == "q4");
	assert(m->getStock(4)->GetLabel() == "q5");	
	cout<<"add Stock to vector is working correctly"<<endl;
	//delete q1;
	//delete q2;
	//delete q3;
	//delete q4;
	//delete q5;
	assert(System::deleteSystem(m));
	


}

void testingModel(){
	testConstructorModel();
	testingAddFlow();
	testingAddSystem();

}	

void testHandle(){ 
	int nhant = numHandleCreated;
	int nbant = numBodyCreated;
	int nhDeleted = numHandleDeleted;
	int nbDeleted = numBodyDeleted;
	System* x = System::createSystem();
	Stock* m = x->createStock(10, "Lucas");
	assert(numHandleCreated == nhant + 2);
	assert(numBodyCreated == nbant + 2);
	{
		Stock* m1 = x->createStock(20, "Gabriel");
		Stock* m2 = x->createStock(30, "Santos");
		m1 = m2;
	}
	System::deleteSystem(x);
	cout << "Handle Body is working correctly" << endl;

}