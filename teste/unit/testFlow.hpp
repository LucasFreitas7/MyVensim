/**
 * @file testFlow.hpp
 * @author Lucas Andrade Freitas
 * @date setember 23, 2019
 * @brief This is the hpp file of the unit tests
 * *
 */
#ifndef TESTEFLOW_HPP
#define TESTEFLOW_HPP
#include "../../src/system.hpp"
#include "../../src/flowImp.hpp"
//#include<iostream>
#include<assert.h>
using namespace std;
//!Test of the Constructor
void testConstructor();/*!<testing if the constructor are seting the name of flow right*/
//!Test of the Equation
void testEquation();/*!<testing if the equation are returning the right value*/
//!Test of set and get Name
void testSetGetName();/*!<testing if the set and get are working*/
//!Test of the Connect
void testConnect();/*!<testing if the connect are really connecting one source and one target on the flow*/
//!Test of the gets and set of Target and Source
void testSourceTarget();/*!<testing if the get and set of source and target are working*/
void testOverloadFlow();/*!<testing overload*/
//! Test all functions of Flow
void testFlow();
#endif
