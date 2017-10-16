#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
    void setup() override;
    void draw() override;


    void drawCircles();
    void drawSquare();
    void drawWithBrush();

    ofImage brush;

};
