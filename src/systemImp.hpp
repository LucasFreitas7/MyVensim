#ifndef SYSTEMIMP_HPP
#define SYSTEMIMP_HPP
#include"stockImp.hpp"
#include"system.hpp"
#include "flowImp.hpp"
#include "bridge.h"
//#include "flowImp.hpp"
#include<vector>

/**
*  class specifying how SystemBody should be implemented
*/
class SystemBody: public Body{
    
    public:
	    //!Constructor
	    SystemBody(Flow* f, Stock* s);/*!<constructor to inicializate the atributes of the class System */
	    //!constructor
	    SystemBody(){}/*!<constructor empty */
		//!Destructor
	    virtual ~SystemBody();/*!< destructor to delete the atributes of the class System*/
		//!Add Stock
	    void add(Stock* x); /*!<this function add one Stock on the container of systems*/
		//!Add Flow
	    void add(Flow* x); /*!<this function add one flow on the container of flows*/
		void add(System* x);
		//!Execute SystemBody
	    void execute(int tempoIncial, int tempoFinal); /*!<this is the most important function, that make all flows run  yours math formula that have one source system and another source but this time like a target*/
		void executeSubSystems(int tempoInicial, int tempoFinal, System* x);
		//!getFlow
		Flow *getFlow(int i); /*<function that returns Flow add in vector*/
		//!getStock
		Stock* getStock(int i);/*<function that returns Stock add in vector*/ 
    	Stock* createStock(float valor, string label);
    	Stock* createStock();

    	
    

	protected:
		vector<Flow*> flows; /*!< container of Flow*/
    	vector<Stock*> stocks;/*!< container of systems*/
		vector<System*> systems;
	private:
		//!Copy Constructor
		SystemBody(SystemBody*){} /*!<operator to make one Stock receive the value of another System*/

};


class SystemHandle: public System, public Handle<SystemBody>{
    
    public:
	    //!Constructor
	    SystemHandle(Flow* f, Stock* s)/*!<constructor to inicializate the atributes of the class System */
	    {
	    	pImpl_ = new SystemBody(f, s);
	    }
	    //!constructor
	    SystemHandle()/*!<constructor empty */
	    {
	    	pImpl_ = new SystemBody();
	    }
		//!Destructor
	    virtual ~SystemHandle(){/*!< destructor to delete the atributes of the class System*/
	    	pImpl_->detach(); 
	    }
		//!Add Stock
	    void add(Stock* x) /*!<this function add one Stock on the container of systems*/
	    {
	    	pImpl_->add(x);
	    }
		//!Add Flow
	    void add(Flow* x) /*!<this function add one flow on the container of flows*/
	    {
	    	pImpl_->add(x);
	    }
		void add(System* x){
			pImpl_->add(x);
		}
		//!Execute SystemHandle
	    void execute(int tempoIncial, int tempoFinal) /*!<this is the most important function, that make all flows run  yours math formula that have one source Stock and another source but this time like a target*/
    	{
    		pImpl_->execute(tempoIncial, tempoFinal);
    	}
		void executeSubSystems(int tempoInicial, int tempoFinal, System* x){
			pImpl_->executeSubSystems(tempoInicial, tempoFinal, x);
		}
		void execute()
		{
		}
    	//!getFlow
    	Flow* getFlow(int i)/*<function that returns Flow add in vector*/ 
    	{
    		return pImpl_->getFlow(i);
    	}
    	//!getStock
    	Stock* getStock(int i)/*<function that returns Stock add in vector*/ 
    	{
    		return pImpl_->getStock(i);
    	}
    	static System* createSystem();
    	Stock* createStock(float valor, string label){
    		return pImpl_->createStock(valor, label);
    	}
    	Stock* createStock(){
    		return pImpl_->createStock();
    	}
    	
    	
    	static bool deleteSystem(SystemHandle *m1);

	
	private:
		//!Copy Constructor
		SystemHandle(SystemHandle*){} /*!<operator to make one Stock receive the value of another System*/

};
#endif //!MODEL_HPP