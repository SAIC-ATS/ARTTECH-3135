#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxFaceTracker2.h"
#include "PastSquare.h"
#include "ofxOsc.h"
//#include "ofxPython.h"

#define HOST "127.0.0.1"
#define PORT 12001
#define NUM_MSG_STRINGS 20

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    
    void makePastSquare();
    void handleOscMsgs();
    void drawPastSquares();
    void captureBG();
    
    ofVideoGrabber grabber;
    
    ofPixels grayscalePixels;
    ofTexture grayscaleTexture;
    
    ofPixels binaryPixels;
    ofTexture binaryTexture;
    
    ofPixels backgroundPixels;
    ofTexture backgroundTexture;
    
    ofPixels frameToShowPixels;
    ofTexture frameToShowTexture;
    
    ofxFaceTracker2 tracker;
    ofxOscReceiver receiver;
    ofxCv::ContourFinder contourFinder;
    
    ofxPanel gui;
    
    ofParameter<bool> invert;
    ofParameter<int> threshold;
    ofParameter<int> erosionIterations;
    ofParameter<int> dilationIterations;
    ofParameter<int> pastSquareMax;

    ofTrueTypeFont dataFont;
    
    std::vector<PastSquare> pastSquareVector;
    
    bool go = true;
    bool bgCaptured = false;
    int current_msg_string;
    int makeSquareCounter = 0;
    int halfWidth = ofGetWidth() / 2;
    int halfHeight = ofGetHeight() / 2;
    int pastSquareCount = 0;
    string msg_strings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];
};

