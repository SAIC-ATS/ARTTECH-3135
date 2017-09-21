#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void update() override;
    void draw() override;

    float angleDegrees = 0;
    float radius = 100;
    float scaleX = 1;
    float scaleY = 1;

};
