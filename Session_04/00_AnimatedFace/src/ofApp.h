#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    // Feature Parameters
    // Feature paremeters describing the head.
    ofColor headColor;
    float headX;
    float headY;
    float headWidth;
    float headHeight;

    // Feature parameters describing the mouth.
    float mouthX;
    float mouthY;
    float mouthWidth;
    float mouthHeight;
    ofColor mouthColor;

    // Feature parameters describing the nose.
    float noseX;
    float noseY;
    float noseWidth;
    float noseHeight;
    ofColor noseColor;

    // Feature parameters describing the eyes.
    float eyeXDistance;
    float eyeY;
    float eyeWidth;
    float eyeHeight;
    float irisOffsetX;
    float irisOffsetY;
    ofColor irisColor;
    float pupilRadius;

};
