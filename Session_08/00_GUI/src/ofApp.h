#pragma once


#include "ofMain.h"
#include "ofxGui.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
 
    void keyPressed(int key) override;
    
    void resetTheGui();
    
    
    // This is a slider, but it is also floating point "value".
    // float radius = 0;
    ofxFloatSlider radius;
    
    // This is a color "widget".
    ofxColorSlider fillColor;
    
    // The position of the circle.
    ofxVec2Slider position;
    
    // Fill / noFill toggle.
    ofxToggle fill;
    
    // Button
    ofxButton resetButton;
    
    // This is the gui panel where we will all of our "widgets".
    ofxPanel gui;
    
    
    bool drawGui = true;
    
};

