#ifndef STOCK_HPP
#define STOCK_HPP
#include<list>
#include<string>
#include<iostream>
#include"model.hpp"
using namespace std;

class Stock : public Model{
    
    public:
        virtual void execute(){}
        //!setEnergy
        virtual void setEnergy(float) = 0; /*!< set the Energy of one Stock*/
        //!getEnergy
        virtual float getEnergy() = 0; /*!< get the Energy of one Stock*/
        //!GetLabel
        virtual string GetLabel() = 0; /*!<get the Label of one Stock*/
        //!setLabel
        virtual void setLabel(string aux) = 0; /*!<set the Label of one Stock*/
    };
#endif //!STOCK_HPP