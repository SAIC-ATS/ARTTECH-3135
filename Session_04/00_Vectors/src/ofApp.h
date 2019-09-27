#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void exit() override;
    
    void mousePressed(int x, int y, int button) override;
    
    std::vector<float> xPositions;

    // std::vector<Flower> xPositions;

    
//    ofColor myColor1;
//    ofColor myColor2;
//    ofColor myColor3;

    // std::vector<ofColor> myColors;
    
};

