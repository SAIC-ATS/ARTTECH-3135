#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void mousePressed(int x, int y, int mouse) override;
    void mouseDragged(int x, int y, int mouse) override;
    void keyPressed(int key) override;

    ofPolyline polyline;

    float position = 0;

};
