
#include"systemImp.hpp"

SystemBody::SystemBody(Flow* f, Stock* s){
    this->flows.push_back(f);
    this->stocks.push_back(s);
}
SystemBody::~SystemBody(){
     while(!this->stocks.empty()){
        delete (StockHandle*) this->stocks.back();
        this->stocks.pop_back();
     }
     while(!this->flows.empty()){
        delete (FlowHandle*) this->flows.back();
        this->flows.pop_back();
     }
     while(!this->systems.empty()){
        delete (FlowHandle*) this->systems.back();
        this->systems.pop_back();

    }

     this->stocks.clear();
     this->flows.clear();
     this->systems.clear();
    

}
void SystemBody::add(Stock* x){
    this->stocks.push_back(x);
}
void SystemBody::add(Flow* x){
    this->flows.push_back(x);
}

void SystemBody::add(System* x){
    this->systems.push_back(x);
}
void SystemBody::execute(int tempoIncial, int tempoFinal){
	int aux = this->flows.size();
    float *v =  new float[aux];
    for(int i = tempoIncial; i < tempoFinal; i++)
    {
        
        for(int w = 0; w < aux; w++)
        v[w] = this->flows[w]->equation();
        for(int j = 0; j < aux; j++){
           // cout << "bbbbbbbbbbbbbbbbbb";
            this->flows[j]->getTarget()->setEnergy((this->flows[j]->getTarget()->getEnergy() + v[j]));
            this->flows[j]->getSource()->setEnergy((this->flows[j]->getSource()->getEnergy()- v[j]));
        }
    }
}
void SystemBody::executeSubSystems(int tempoInicial, int tempoFinal, System* x){
    this->add(x);
    int aux = this->systems.size();
    for (int i = 0; i < aux; i++){
       // cout << "aaaaaaaaaaaa";
        this->systems[i]->execute(tempoInicial, tempoFinal);
    }
    this->execute(tempoInicial, tempoFinal);
}
Flow* SystemBody:: getFlow(int i)
{
   return this->flows[i];
}

Stock* SystemBody:: getStock(int i)
{
    return this->stocks[i];
}

System* SystemHandle::createSystem(){
    System* m1 = new SystemHandle();
    //this->systems.push_back(m1);
    return m1;
}

System* System::createSystem() {
    return SystemHandle::createSystem();
 }

bool SystemHandle::deleteSystem(SystemHandle *m1){
	delete m1->pImpl_;
    m1->pImpl_ = 0;
    if(m1->pImpl_ == NULL) return true;
    return false;
}

bool System::deleteSystem(System *m1){
	return SystemHandle::deleteSystem((SystemHandle*)m1);
}

 Stock* SystemBody:: createStock(float valor, string label)
 {
 	Stock* s = new StockHandle(valor, label);
    this->stocks.push_back(s);
 	return s;
 }


 Stock* SystemBody:: createStock()
 {
    Stock* s = new StockHandle();
     this->stocks.push_back(s);
    return s;
 }

