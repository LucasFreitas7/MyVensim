#ifndef FLOW_HPP
#define FLOW_HPP
#include "stock.hpp"
//#include "model.hpp"
//#include <string>
using namespace std;

/**
* Virtual class specifying how flow should be implemented
*/

class Flow: public Model{
    public:
    virtual void execute() = 0;
    //!Equation
    virtual float equation()= 0; /*!< the virtual function equation its reponseble to make the math formula that will be execute on the flows  */
    //!setName
    virtual void setName(string name) = 0; /*!< set the name of the flow*/
    //!GetName
    virtual string getName() = 0;/*!< set the name of the flow*/
    //!Connect
    virtual void connect(Stock *x, Stock *y) = 0; /*!< virtual function that connects one flow on two systems, one on the source and another on the target*/
    //!SetTarget
    virtual void setTarget(Stock* x)= 0;/*!< set the flow Target*/
    //!SetSource
    virtual void setSource(Stock* x) = 0;/*!< set the flow Source*/
    //!GetSource
    virtual Stock* getSource() = 0;/*!< return the flow Source*/
    //!GetTarget
    virtual Stock* getTarget() = 0;/*!< return the flow Target*/

};
#endif // !FLOW_HPP