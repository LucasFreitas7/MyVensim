/**
 * @file testSystem.hpp
 * @author Lucas Andrade Freitas
 * @date setember 23, 2019
 * @brief This is the hpp file of the unit tests
 * *
 */
#ifndef TESTSTOCK_HPP
#define TESTSTOCK_HPP
#include "../../src/system.hpp"
//#include<iostream>
#include<assert.h>
//#include "../../src/flowImp.hpp"
using namespace std;
//!Test of the Constructor
void testConstructorSystem();/*!<testing if the constructor is working correctly */
//!Test of set and get
void testSetGetSystem();/*!<testing if the set and get are working*/
void testingOverload(); /*!<testing overload*/
//! Test all functions of System
void testingSystem();


#endif