#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofImage cartwheeler;

    float xPosition = 0;
    float yPosition = 0;
    float angleDeg = 0;

    float angleDegIncrement = 0;

};

