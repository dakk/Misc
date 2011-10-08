/*
 * VideoTest.h
 *
 *  Created on: Aug 20, 2011
 *      Author: Davide Gessa
 */

#ifndef VIDEOTEST_H_
#define VIDEOTEST_H_

#include "Test.h"

class VideoTest : public Test
{
public:
					VideoTest();
					~VideoTest();
			int		Run();
			void	Trollize(IplImage* frame);

protected:
	CvMemStorage* 				fStorage;
	CvHaarClassifierCascade* 	fCascade;
	IplImage*					fImage;
};

#endif /* VIDEOTEST_H_ */
