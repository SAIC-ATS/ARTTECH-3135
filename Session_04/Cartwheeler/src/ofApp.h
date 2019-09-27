#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofImage cartwheeler;

    float xPosition = 0;
    float yPosition = 0;
    float angleDeg = 0;

    float angleDegIncrement = 0;

};

