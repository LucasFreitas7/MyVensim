#include"testFlow.hpp"

class Myflow: public FlowHandle{
    public:
        
        //!Equation
        float equation() /*!< equation of the logistic case*/
        {
             float aux = (0.01 * this->getSource()->getEnergy());
             return aux;
        }
};

void testConstructor(){
    System* modelo = System::createSystem();

    Flow* teste1 = modelo->createFlow<Myflow>("Flow1");
    assert("Flow1" ==  teste1->getName());
    cout << "Constructor are working" << endl;
    assert(System::deleteSystem(modelo));
}
void testEquation(){
    System* modelo = System::createSystem();
    Flow *f = modelo->createFlow<Myflow>();
    Stock* x1 = modelo->createStock(100, "x1");
    Stock* x2 = modelo->createStock(10, "x2");
    f->connect(x1, x2);
    float test = f->equation();
    assert(test == 1);
    cout << "Connect are working" << endl;
    assert(System::deleteSystem(modelo));
    //delete f;
}
void testSetGetName(){
    System* m = System::createSystem();
    Flow* f= m->createFlow<Myflow>("Flow7");
    f->setName("Flow1");
    assert("Flow1" == f->getName());
    cout << "Get and Set Name are working" << endl;
    assert(System::deleteSystem(m));
}
void testConnect(){
    System* m = System::createSystem();
    Flow * f = m->createFlow<Myflow>();
    Stock* x1= m->createStock(100, "x1");
    Stock* x2= m->createStock(10, "x2");
    f->connect(x1, x2);
    assert(f->getSource()->GetLabel() == x1->GetLabel());
    assert(f->getTarget()->GetLabel()== x2->GetLabel());
    cout << "Connect are working" << endl;
    assert(System::deleteSystem(m));
   // delete f;
}
void testSourceTarget(){

    System* m = System::createSystem();
    Flow * f = m->createFlow<Myflow>();
    Stock* x1= m->createStock(100, "x1");
    Stock* x2= m->createStock(10, "x2");
    f->setTarget(x2);
    f->setSource(x1);
    assert(f->getSource()->GetLabel() == x1->GetLabel());
    assert(f->getTarget()->GetLabel()== x2->GetLabel());
    cout << "Get and Set source and target are working" << endl;
    //delete f;
    assert(System::deleteSystem(m));

}
void testOverloadFlow()
{
    System* m = System::createSystem();
    Flow* x= m->createFlow<Myflow>("xxx");
    Flow* y = x;
    assert(x->getName() == y->getName());
    cout<<"the iverload of = of the flow its working"<<endl;
    assert(System::deleteSystem(m));

}
void testFlow(){
    testEquation();
    testConstructor();
    testSetGetName();
    testConnect();
    testSourceTarget();
    testOverloadFlow();
}