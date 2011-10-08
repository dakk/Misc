/*
 * VideoTest.cpp
 *
 *  Created on: Aug 20, 2011
 *      Author: Davide Gessa
 */

#include "VideoTest.h"

VideoTest::VideoTest() : Test("Realtime Face Replace")
{
	
}

VideoTest::~VideoTest()
{
}


/** Replace your face with a trollface */
void VideoTest::Trollize(IplImage* frame)
{	
	cvClearMemStorage( fStorage );
    int i;


	// Detect faces and store them in a sequence
    CvSeq* faces = cvHaarDetectObjects(frame, fCascade, fStorage, 1.2, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(20, 20));

    // Loop the number of faces found.
    for( i = 0; i < (faces ? faces->total : 0); i++ )
    {
		// Create a new rectangle for drawing the face
        CvRect* r = (CvRect*) cvGetSeqElem(faces, i);

		// Fix invalid cordinates
		r->x -= 20;
		r->y -= 20;

		if(r->x < 0)
			r->x = 0;
		
		if(r->y < 0)
			r->y = 0;
		
		r->width += 50;
		r->height += 50;

		if(r->width > frame->width)
			r->width = frame->width;
		if(r->height > frame->height)
			r->height = frame->height; 

		// Create a new image to resize the original trollface
		IplImage *temp = cvCreateImage(cvSize(r->width, r->height), frame->depth, frame->nChannels);

		// Swap the real image in the temp buffer with the new dimension
		cvResize(fImage, temp);

		// Specify the region of interest where put the image
		cvSetImageROI(frame, *r);

		// Swap trollface in the specified region
		cvAddWeighted(temp, 1.0, frame, 1.0, 0, frame);

		// Reset the region
		cvSetImageROI(frame, cvRect(0, 0, frame->width, frame->height));
	    cvReleaseImage( &temp );
    }
}




int VideoTest::Run()
{
	CvCapture* capture;
    IplImage* frame;
    IplImage* frame_mod;

	// Initialize the capture device
	capture = cvCaptureFromCAM(-1);

	if(!capture)
    {
		ShowError("Cannot find webcam");
		return -1;
	}
	
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 700);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 700);
	cvSetCaptureProperty(capture, CV_CAP_PROP_CONTRAST, 0);

	fStorage = cvCreateMemStorage(0);

	// Load default cascade for faces
	fCascade = (CvHaarClassifierCascade*) cvLoad("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml", 0, 0, 0 );

	if(!fCascade)
	{
		ShowError("Cannot load frontalface cascade");
		return -1;
	}

	// Load the trollface
	fImage = cvLoadImage("data/trollface.png", CV_LOAD_IMAGE_UNCHANGED);

	if(!fImage)
	{
		ShowError("Cannot load troll image");
		return -1;
	}
	
	
	// Create windows to display results
    cvNamedWindow("Capture", 1);
    cvNamedWindow("VideoTest", 1);


	for(;;)
    {
		// Retrive data from webcam and copy the frame to frame_mod
		if(!cvGrabFrame(capture))
            break;

		frame = cvRetrieveFrame(capture);

        if(!frame)
            break;
			
		frame_mod = cvCreateImage(cvSize(frame->width,frame->height), frame->depth, frame->nChannels);
			

		// Show image on capture screen
		cvFlip(frame, frame, -1);
		cvFlip(frame, frame_mod, 0);
		cvShowImage("Capture", frame_mod);

		// Elaborate and show the result
		Trollize(frame_mod);
		cvShowImage("VideoTest", frame_mod);
			
		cvReleaseImage(&frame_mod);

			
		// Esc key
        if(cvWaitKey(10) >= 0)
            break;
    }

    cvReleaseCapture(&capture);
    
    cvDestroyWindow("VideoTest");
    cvDestroyWindow("Capture");
	cvReleaseImage(&fImage);


    return 0;
}
