#pragma once


#include "ofMain.h"
#include "ofxGui.h"
#include "Tendril.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
    
    // The Tendril to be constructed.
    Tendril tendril;
    
    // The gui.
    ofxPanel gui;
    
    // The start angle of the tendril segment.
    ofxFloatSlider startAngleDeg;
    
    // The end angle of the tendril segment.
    ofxFloatSlider endAngleDeg;
    
    // The length of the first tendril segment.
    ofxFloatSlider startLength;
    
    // The length of the first tendril segment.
    ofxFloatSlider endLength;
    
    // The number of segments in the tendril.
    ofxIntSlider numSegments;
};
