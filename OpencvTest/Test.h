/*
 * Test.h
 *
 *  Created on: Aug 20, 2011
 *      Author: Davide Gessa
 */

#ifndef TEST_H_
#define TEST_H_

#include <cv.h>
#include <highgui.h>


/** Base class for all tests */
class Test
{
public:
					Test(string description);
					~Test();
			void	ShowError(string);
	virtual int		Run() = 0;
};

#endif /* TEST_H_ */
