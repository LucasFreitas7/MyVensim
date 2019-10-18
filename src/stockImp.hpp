#ifndef STOCKIMP_HPP
#define STOCKIMP_HPP
#include<list>
#include<string>
#include<iostream>
#include"stock.hpp"
#include "bridge.h"
using namespace std;

class StockBody: public Body{
    
    public:
        virtual void execute() {}
        //!Constructor
        StockBody(float energy = 0, string Label = "null"); /*!< constructor to inicializate the atributes of the class sytem*/
        //!Destructor
        virtual ~StockBody();/*!< destructor to delete the atributes of the StockBody*/
        //!setEnergy
        void setEnergy(float); /*!< set the Energy of one StockBody*/
        //!getEnergy
        float getEnergy(); /*!< get the Energy of one StockBody*/
        //!Operator==
        friend ostream& operator<<(ostream& os, const StockBody &p); /*!< create operator << of the Flow*/
        //!GetLabel
        string GetLabel(); /*!<get the Label of one StockBody*/
        //!setLabel
        void setLabel(string aux); /*!<set the Label of one StockBody*/
        
    protected:
    	float energy; /*!< energy of StockBody*/
    	string label; /*!< name of StockBody*/
    private:
    };

class StockHandle: public Stock, public Handle<StockBody>{

public:
    virtual void execute() {}
    //!Constructor
    StockHandle(float energy = 0, string Label = "null") /*!< constructor to inicializate the atributes of the class sytem*/
    {
    	pImpl_ = new StockBody(energy, Label);
    }

    //!Destructor
    virtual ~StockHandle()/*!< destructor to delete the atributes of the StockHandle*/
    {
    	//delete pImpl_;
    }
    //!setEnergy
    void setEnergy(float energy) /*!< set the Energy of one StockHandle*/
    {
    	pImpl_->setEnergy(energy);
    }
    //!getEnergy
    float getEnergy() /*!< get the Energy of one StockHandle*/
    {
    	return pImpl_->getEnergy();
    }
    //!Operator==
    friend ostream& operator<<(ostream& os, const StockHandle &p) /*!< create operator << of the Flow*/
    {
    	os << p.pImpl_;
    	return os;
    }
    //!GetLabel
    string GetLabel() /*!<get the Label of one StockHandle*/
    {
    	return pImpl_->GetLabel();
    }
    //!setLabel
    void setLabel(string aux) /*!<set the Label of one StockHandle*/
    {
    	pImpl_->setLabel(aux);
    }
private:
    //!Copy constructor
    StockHandle(StockHandle* sh)/*!< Construtor to inicializate one StockHandle equal to another*/
    {
    	*this = *sh;
    }
    //!Operator=
	StockHandle & operator=(StockHandle & s) /*!<operator to make one StockHandle receive the value of another StockHandle*/
	{
        Handle<StockBody>::operator=((StockHandle&)s);
		return *this;
	}
};
#endif //!SystemImp_HPP