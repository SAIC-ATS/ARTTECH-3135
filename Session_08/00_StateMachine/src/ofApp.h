#pragma once


#include "ofMain.h"
#include "ofxCvHaarFinder.h"


class ofApp: public ofBaseApp
{
public:
    enum State
    {
        NOT_TRACKING,
        TRACKING
    };

    void setup() override;
    void update() override;
    void draw() override;

    State currentState = NOT_TRACKING;
    
    ofVideoGrabber grabber;
    ofxCvHaarFinder finder;

    ofSoundPlayer enterSound;
    ofSoundPlayer leaveSound;

};

