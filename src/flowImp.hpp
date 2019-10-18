#ifndef FLOWIMP_HPP
#define FLOWIMP_HPP
//#include "stockImp.hpp"
//#include <string>
#include "flow.hpp"
#include "bridge.h"
using namespace std;

/**
* Virtual class specifying how flow should be implemented
*/

class FlowBody: public Body{
    public:
    void execute(){}
    //!Constructor
    FlowBody(string name = "null"); /*!< constructor that make the target and source get null value*/
    //!Destructor
    ~FlowBody();/*!< destructor that make the target and source get null value and afther this delete target and source*/
    //!Equation
    virtual float equation(){return 0;} /*!< the virtual function equation its reponseble to make the math formula that will be execute on the FlowImps  */
    //!setName
    void setName(string name); /*!< set the name of the FlowBody*/
    //!GetName
    string getName();/*!< set the name of the FlowBody*/
    //!Connect
    void connect(Stock *x, Stock *y); /*!< virtual function that connects one FlowBody on two systems, one on the source and another on the target*/
    //!SetTarget
    void setTarget(Stock* x);/*!< set the FlowBody Target*/
    //!SetSource
    void setSource(Stock* x);/*!< set the FlowBody Source*/
    //!GetSource
    Stock* getSource();/*!< return the FlowBody Source*/
    //!GetTarget
    Stock* getTarget();/*!< return the FlowBody Target*/

    protected:
	string name; /*!< name of FlowBody*/
    Stock * target; /*!< Target of FlowBody */
    Stock * source; /*!< Source of FlowBody */
    private:
    //!Copy constructor
    FlowBody(FlowBody*);/*!< Construtor to inicializate one FlowBody equal to another*/
    //!Operator=
    FlowBody & operator=(FlowBody & s); /*!<operator to make one flow receive the value of another flow*/

};

class FlowHandle: public Flow , public Handle <FlowBody>{
    public:
    void execute() {}
    //!Constructor
    FlowHandle(string name = "null") /*!< constructor that make the target and source get null value*/
    {
            pImpl_ = new FlowBody(name);
    }
    //!Destructor
    ~FlowHandle()/*!< destructor that make the target and source get null value and afther this delete target and source*/
    {

    }
    //!Equation
    virtual float equation()/*!< the virtual function equation its reponseble to make the math formula that will be execute on the FlowImps  */
    {
        return pImpl_->equation();
    }
    //!setName
    void setName(string name) /*!< set the name of the FlowHandle*/
    {
        pImpl_->setName(name);
    }
    //!GetName
    string getName()/*!< set the name of the FlowHandle*/{
        return pImpl_->getName();
    }
    //!Connect
    void connect(Stock *x, Stock *y)/*!< virtual function that connects one FlowHandle on two systems, one on the source and another on the target*/
    {
        pImpl_->connect(x,y);
    }
    //!SetTarget
    void setTarget(Stock* x)/*!< set the FlowHandle Target*/{
        pImpl_->setTarget(x);
   }
    //!SetSource
    void setSource(Stock* x)/*!< set the FlowHandle Source*/{
        pImpl_->setSource(x);
    }
    //!GetSource
    Stock* getSource()/*!< return the FlowHandle Source*/{
        return pImpl_->getSource();
   }
    //!GetTarget
    Stock* getTarget()/*!< return the FlowHandle Target*/{
        return pImpl_->getTarget();
   }

   
    //!Copy constructor
    FlowHandle(FlowHandle* sh)/*!< Construtor to inicializate one FlowHandle equal to another*/{
        *this = *sh;
   }
    //!Operator=
    FlowHandle & operator=(FlowHandle & s) /*!<operator to make one flow receive the value of another flow*/{
   if (&s == this) return *this;

        pImpl_->getName().clear();
        pImpl_->setName(s.getName());

        return *this;
}

};
#endif // !FLOW_HPP