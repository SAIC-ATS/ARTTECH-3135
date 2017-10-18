#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofVideoGrabber grabber;

    ofPixels grayscalePixels;
    ofTexture grayscaleTexture;

    int threshold = 127;

};
