/*
 * Test.cpp
 *
 *  Created on: Aug 20, 2011
 *      Author: Davide Gessa
 */
#include <stdio.h>

#include "Test.h"

Test::Test(string description)
{
	printf("Starting test: %s\nRealized by: Davide Gessa\n\n", description.c_str());
}

Test::~Test(){}


void Test::ShowError(string str)
{
	printf("[ER] %s\n", str.c_str());
}
