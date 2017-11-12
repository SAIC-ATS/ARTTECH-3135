#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxFaceTracker2.h"
//#include "ofxPython.h"
#include "PastSquare.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void makePastSquare();
            
    ofVideoGrabber grabber;
        
    ofPixels grayscalePixels;
    ofTexture grayscaleTexture;
    
    ofPixels binaryPixels;
    ofTexture binaryTexture;
    
    ofPixels frameToShowPixels;
    ofTexture frameToShowTexture;
    
    ofxFaceTracker2 tracker;
    
    ofxCv::ContourFinder contourFinder;
    
    ofxPanel gui;
    ofParameter<bool> invert;
    ofParameter<int> threshold;
    ofParameter<int> erosionIterations;
    ofParameter<int> dilationIterations;
    
    ofTrueTypeFont dataFont;
    
    std::vector<PastSquare> pastSquareVector;
    
    bool go = true;
    
    int makeSquareCounter = 0;
    int halfWidth = ofGetWidth() / 2;
    int halfHeight = ofGetHeight() / 2;
    int pastSquareCount = 0;
    int pastSquareMax = 25;
    
    float textSpeed;
};

