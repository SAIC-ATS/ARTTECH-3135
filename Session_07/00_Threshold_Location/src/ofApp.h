#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    // Video camera input.
    ofVideoGrabber grabber;

    // Pixel data on RAM accessed and manipulated by the CPU.
    ofPixels pixels;
    
    // A copy of the pixels data living on the GPU RAM so it can be drawn to the screen.
    ofTexture texture;
    
    // ofImage = ofPixels + ofTexture
    
    // Brightness threshold is half way between 0 - 255.
    float brightnessThreshold = 127;
    
    // Average position of the light pixels.
    glm::vec2 position;
    
    
    ofPolyline line;
    
};

