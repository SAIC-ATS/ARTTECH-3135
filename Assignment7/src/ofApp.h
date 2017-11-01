#pragma once


#include "ofMain.h"
#include "ofxCvHaarFinder.h"


class ofApp : public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
    void mousePressed(int x, int y, int button);

    ofVideoGrabber grabber;
    ofxCvHaarFinder finder;
    ofPixels grayscalePixels;
    ofTexture grayscaleTexture;
    
    ofSoundPlayer soundPlayer;
    
    int threshold = 127;
    bool mouthOpen;
};
