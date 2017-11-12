#pragma once

#include "ofMain.h"

class PastSquare
{
public:
    PastSquare(ofVideoGrabber grabber, ofPixels frameToShowPixels, int pastSquareIndex);
    ~PastSquare();
    
    void setup();
    void update();
    void draw(bool go, ofVideoGrabber grabber);
    void blur(bool go, ofVideoGrabber grabber);
    
    ofPixels squarePix;
    ofRectangle pastSquare;
    ofTexture pastSquareTexture;
    
    int pastSquareIndex;
    bool bgCaptured = false;

};
