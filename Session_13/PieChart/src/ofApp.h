#pragma once


#include "ofMain.h"
#include "ofxGui.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
        
    // The gui.
    ofxPanel gui;
    
    std::vector<ofxIntSlider> sliders;
        
};
