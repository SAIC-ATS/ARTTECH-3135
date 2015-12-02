#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"


class ofApp : public ofBaseApp {
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);

	
	ofxKinect kinect;

	ofxCvColorImage colorImg;
	
	ofxCvGrayscaleImage grayImage; // grayscale depth image
	ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
	ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
	
	ofxCvContourFinder contourFinder;
	
	int nearThreshold;
	int farThreshold;
	
	int angle;

    float alpha;
    ofPoint smoothedPoint;

};
