#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    // void applyPixelsToGOL(const ofPixels& pixels);


    void keyPressed(int key) override;

    ofFbo fbo;

};
