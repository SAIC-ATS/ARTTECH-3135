#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    // We override the draw function provided by ofBaseApp.
    void draw() override;

    float angleDeg = 45;
    float angleIncrementDeg = 0.5;

};
