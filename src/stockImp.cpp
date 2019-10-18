#include"stockImp.hpp"
StockBody::StockBody(float energy, string label){
    this->energy = energy;
    this->label = label;
}

StockBody::~StockBody(){}
void StockBody::setEnergy(float energy)
{
	this->energy = energy;
}
float StockBody:: getEnergy()
{
	return this->energy;
}
ostream& operator<<(ostream& os, const StockBody &p){
    os << "Label: " << p.label << "  Energy = " << p.energy << endl;
    return os;
}

string StockBody:: GetLabel()
{
	return this->label;
}

void StockBody:: setLabel(string aux){
	this->label = aux;
}


