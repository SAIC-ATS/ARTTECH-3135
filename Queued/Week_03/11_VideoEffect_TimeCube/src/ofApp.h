#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
    void keyPressed(int key) override;

    ofVideoGrabber grabber;

    ofPixels pixels;
    ofTexture texture;

    int maxBufferSize = 255;
    std::vector<ofPixels> pixelBuffer;

    ofPixels timeMapPixels;
    ofTexture timeMapTexture;
    bool useLinearGradient = false;

    bool isBuffering = true;

};
