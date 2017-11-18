#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxFaceTracker2.h"
#include "PastSquare.h"
#include "ofxOsc.h"
#include "ofxKinectV2.h"
#include "ofxJSON.h"
//#include "ofxPython.h"

#define HOST "127.0.0.1"
#define PORT 12001
#define NUM_MSG_STRINGS 20

// This flag uses a pre-stored background subtracted
// video. Comment this line to use the Kinect, which is
// connected.
#define _USE_VIDEO

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
    void setupKinect();
    void updateKinect();
    void updatePolyline(float widthOffset, float heightOffset);

    ofVideoGrabber grabber;
    ofVideoPlayer rgbVidPlayer;

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
    
    // Kinect Gui group.
    ofxGuiGroup kinectGroup;
    
    // Kinect.
    ofxKinectV2 * kinect;
    ofTexture texDepth;
    ofTexture texRGB;
    
    // OpenCV UI parameters.
    ofxGuiGroup cvGroup;
    ofxFloatSlider minArea, maxArea, threshold;
    
    ofxPanel gui;
    
    ofParameter<bool> invert, bgSubtractionEnabled, contoursVisible;
    ofParameter<int> erosionIterations, dilationIterations, pastSquareMax, pastSquareSpawnInterval;

    ofTrueTypeFont dataFont;
    
    ofxJSONElement faceJSON;
    ofxJSONElement facePoints;
    
    std::vector<PastSquare> pastSquareVector;
    std::vector<std::pair<string, ofRectangle>> textVector;

    bool go = true;
    bool bgCaptured = false;
    float timers[NUM_MSG_STRINGS];
    int current_msg_string;
    int makeSquareCounter = 0;
    int pastSquareCount = 0;
    std::string msg_strings[NUM_MSG_STRINGS];
    
    std::string dataText;
    std::array<string, 5> testText = {"here is some text\n", "and here's a little more text\n", "hey look it's text\n", "this is a string of text\n", "a text string is I\n"};
    
private:
    bool showTexture = false;
#ifdef _USE_VIDEO
    ofVideoPlayer         depthVidPlayer;
#endif
    
    ofPolyline newPoly;
};

