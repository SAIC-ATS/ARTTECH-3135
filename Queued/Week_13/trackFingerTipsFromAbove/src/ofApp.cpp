#include "ofApp.h"

void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	// enable depth->video image calibration
	kinect.setRegistration(true);
    
	kinect.init();
	kinect.open();		// opens first available kinect

    colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	grayThreshNear.allocate(kinect.width, kinect.height);
	grayThreshFar.allocate(kinect.width, kinect.height);
	
	nearThreshold = 199;
	farThreshold = 185;

	ofSetFrameRate(60);
	
	angle = 0;
	kinect.setCameraTiltAngle(angle);

    // the smoothing factor.  higher numbers are less responsive and smoother.
    // lower numbers are more responsive and less smooth
    alpha = 0.90;
}


void ofApp::update()
{	
	ofBackground(100, 100, 100);
	
	kinect.update();
	
	// there is a new frame and we are connected
	if(kinect.isFrameNew()) {
		
		// load grayscale depth image from the kinect source
		grayImage.setFromPixels(kinect.getDepthPixels());
		// we do two thresholds - one for the far plane and one for the near plane
		// we then do a cvAnd to get the pixels which are a union of the two thresholds
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(nearThreshold, true);
        grayThreshFar.threshold(farThreshold);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
		// update the cv images
		grayImage.flagImageChanged();
		
		// find contours which are between the size of 100 pixels and 1/2 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayImage, 100, (kinect.width*kinect.height)/2, 1, false);
	}


    // Find the tip of the biggest blob.  We only search for one blob.
    for (int i = 0; i < contourFinder.nBlobs; i++){
        float maxY = std::numeric_limits<float>::lowest();
        std::size_t index = 0;
        std::vector<ofPoint>& points = contourFinder.blobs[i].pts;

        // go around contour to find the highest value of Y (i.e. the lowest in our setup).
        for (int p = 0; p < points.size(); ++p)
        {
            if (points[p].y > maxY)
            {
                maxY = points[p].y;
                index = p;
            }
        }

        // Smooth the position with a simple low pass filter.
        smoothedPoint = smoothedPoint * alpha + points[index] * (1.0 - alpha);
    }



}


void ofApp::draw() {
	
	ofSetColor(255, 255, 255);
	
    kinect.draw(0, 0);
    grayImage.draw(10, 320, 400, 300);
    contourFinder.draw(10, 320, 400, 300);

    ofDrawEllipse(smoothedPoint, 20, 20);
}



void ofApp::exit() {
	kinect.setCameraTiltAngle(0); // zero the tilt on exit
	kinect.close();
}



void ofApp::keyPressed (int key) {
	switch (key) {
		case '>':
		case '.':
			farThreshold ++;
			if (farThreshold > 255) farThreshold = 255;
			break;
			
		case '<':
		case ',':
			farThreshold --;
			if (farThreshold < 0) farThreshold = 0;
			break;
			
		case '+':
		case '=':
			nearThreshold ++;
			if (nearThreshold > 255) nearThreshold = 255;
			break;
			
		case '-':
			nearThreshold --;
			if (nearThreshold < 0) nearThreshold = 0;
			break;
    }
}
