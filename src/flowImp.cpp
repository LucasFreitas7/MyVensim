#include"flowImp.hpp"
FlowBody::FlowBody(string name){
    this->name = name;
    this->target = nullptr;
    this->source = nullptr;
}
FlowBody::FlowBody(FlowBody* m){  
    if(m == this)
        return;
    this->setName(m->getName());
    this->setSource(m->getSource());
    this->setTarget(m->getTarget());
}

FlowBody::~FlowBody(){
    //if (this->source != nullptr)
        //delete this->source;
    //if(this->target != nullptr)
        //delete this->target;
}
void FlowBody::setName(string name){
    this->name = name;
}
void FlowBody::setTarget(Stock* x){
    this->target = x;
}
void FlowBody::setSource(Stock* y){
    this->source = y;
}
void FlowBody::connect(Stock* x, Stock* y)
{
     this->setSource(x);
    this->setTarget(y);

}
Stock* FlowBody::getTarget(){
    return this->target;
}
Stock* FlowBody::getSource(){
    return this->source;
}
FlowBody& FlowBody::operator=(FlowBody &s){
    if(&s == this)
        return *this;

   // delete this->source;
    //delete this->target;
    
    this->source = s.getSource();
    this->target = s.getTarget();
    return *this;
}

string FlowBody::getName(){
    return name;
}