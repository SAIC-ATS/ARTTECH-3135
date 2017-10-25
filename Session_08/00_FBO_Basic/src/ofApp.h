#pragma once


#include "ofMain.h"


class ofApp : public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofFbo fbo0;
    ofFbo fbo1;

};
