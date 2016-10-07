#pragma once


#include "ofMain.h"
#include "Ball.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    std::vector<Ball> crowd;

};
