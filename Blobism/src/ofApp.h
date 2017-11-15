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
    void drawText();
    
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
    ofParameter<int> pastSquareSpawnRate;

    ofTrueTypeFont dataFont;
    
    std::vector<PastSquare> pastSquareVector;
    std::vector<std::pair<string, ofRectangle>> textVector;

    bool go = true;
    bool bgCaptured = false;
    float timers[NUM_MSG_STRINGS];
    int current_msg_string;
    int makeSquareCounter = 0;
    int halfWidth = ofGetWidth() / 2;
    int halfHeight = ofGetHeight() / 2;
    int pastSquareCount = 0;
    std::string msg_strings[NUM_MSG_STRINGS];
    
    std::string dataText;
    std::array<string, 5> testText = {"here is some text\n", "and here's a little more text\n", "hey look it's text\n", "this is a string of text\n", "a text string is I\n"};
};

