#pragma once


#include "ofMain.h"
#include "ofxCvHaarFinder.h"


class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    ofVideoGrabber grabber;
    ofxCvHaarFinder finder;

};
