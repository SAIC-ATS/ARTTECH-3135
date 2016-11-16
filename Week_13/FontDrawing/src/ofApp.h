#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void mousePressed(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    void keyPressed(int key);

    void drawTangle(float x, float y);

    std::vector<ofPolyline> paths;

    ofPoint penPosition;
    ofPoint lastPenPosition;

    float curvePosition = 0;

};
