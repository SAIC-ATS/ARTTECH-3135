#pragma once


#include "ofMain.h"
#include "Ball.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    Ball ball0;
    Ball ball1;
    Ball ball2;

};
