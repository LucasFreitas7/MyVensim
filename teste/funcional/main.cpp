/**
 * @file main.cpp
 * @author Gabriel Bicalho Ferreira
 * @date setember 18, 2019
 * @brief This is the main file of the funcional tests
 * *
 */

/**
* \mainpage Description
* The objective of this software, is simulate flows and systems making one model, who can conecct systems on flow, to simulate any math formula

* \section library_sec Libraries used in this Project
* \subsection library1 Cassert Iostream Cmath.h
* This library allow us to define statements that our program must pass
*/
#include"testeFuncional1.hpp"
#include"testeFuncional2.hpp"
#include"testeFuncional3.hpp"
using namespace std;

int main(){
	logistics();
	Allconected();
	exponential();

	
	return 0;
	 /*!< Function main*/
}