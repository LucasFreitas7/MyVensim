#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include"flow.hpp"
//#include"flowImp.hpp"
//#include "model.hpp"
//#include "stock.hpp"
#include<vector>

/**
*  class specifying how ModelImp should be implemented
*/
class System: public Model{
    
    public:
	    //virtual void add(Stock* x) = 0; /*!<this function add one Stock on the container of systems*/
		//!Add Flow
	    virtual void add(Flow* x)= 0; /*!<this function add one flow on the container of flows*/
		//virtual void add(System *x) = 0;
		//!Execute ModelImp
		virtual void execute(int tempoIncial, int tempoFinal) = 0; /*!<this is the most important function, that make all flows run  yours math formula that have one source Stock and another source but this time like a target*/
		virtual void executeSubSystems(int tempoInicial, int tempoFinal, System* x) = 0;
			//!getFlow
			virtual Flow *
			getFlow(int i) = 0; /*<function that returns Flow add in vector*/
		//!getStock
		virtual Stock* getStock(int i) = 0;/*<function that returns Stock add in vector*/ 
    	static System* createSystem();
    	static bool deleteSystem(System *m);
    	virtual Stock* createStock(float valor, string label) = 0;
   	    template <typename TYPE_FLOW>
    	Flow* createFlow()
    	{
        	 Flow* x = new TYPE_FLOW;
             add(x);
       
       		 return x;
    	}
    	template <typename TYPE_FLOW2>
		Flow* createFlow(string nome)
    	{
        	 Flow* x = new TYPE_FLOW2;
        	 x->setName(nome);
             add(x);
       
       		 return x;
    	}

        virtual Stock* createStock()=0;
       


};
#endif //!MODEL_HPP