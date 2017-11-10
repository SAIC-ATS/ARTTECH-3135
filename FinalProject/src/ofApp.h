#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxFaceTracker2.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void makePastSquare();
    
    std::vector<std::pair<ofRectangle, std::pair<ofTexture, ofPixels>>> pastSquareVector;

    ofxPanel gui;
    ofParameter<int> threshold;
    ofParameter<int> erosionIterations;
    ofParameter<int> dilationIterations;
    
    ofVideoGrabber grabber;
    ofPixels squarePix;
    
    ofPixels grayscalePixels;
    ofTexture grayscaleTexture;
    
    ofPixels backgroundPixels;
    ofTexture backgroundTexture;
    
    ofPixels frameToShowPixels;
    ofTexture frameToShowTexture;
    
    ofxFaceTracker2 tracker;
    
    ofTrueTypeFont dataFont;

    bool go = true;
    bool bgCaptured = false;
    
    int makeSquareCounter = 0;
    int halfWidth = ofGetWidth() / 2;
    int halfHeight = ofGetHeight() / 2;
    
    float textSpeed;
};
