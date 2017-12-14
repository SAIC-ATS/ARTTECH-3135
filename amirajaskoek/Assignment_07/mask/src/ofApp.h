#pragma once


#include "ofMain.h"
#include "ofxCvHaarFinder.h"


class ofApp : public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofVideoGrabber grabber;
    ofxCvHaarFinder finder;
    
    ofImage pandaMask;

    ofImage kitsuneMask;
    
    ofImage fan;
};
