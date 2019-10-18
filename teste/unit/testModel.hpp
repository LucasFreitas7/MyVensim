/**
 * @file testModel.hpp
 * @author Lucas Andrade Freitas
 * @date setember 23, 2019
 * @brief This is the hpp file of the unit tests
 * *
 */
#ifndef TESTMODEL_HPP
#define TESTMODEL_HPP
#include <assert.h>
//#include <iostream>
#include "../../src/flowImp.hpp"

#include "../../src/system.hpp"
using namespace std;
//!Test of the Constructor
void testConstructorModel();/*!<testing if the constructor are seting the vector Flow and vector System  correctly*/
//! test of add vector Flow
void testingAddFlow(); /*!<testing if the add in the flow vector was done correctly*/
//!test of add vector System
void testingAddSystem(); /*!<testing if the add in the System vector was done correctly*/
//! Test all functions of Flow
void testingModel();

void testHandle();

#endif