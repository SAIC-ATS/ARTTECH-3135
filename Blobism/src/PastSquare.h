#pragma once

#include "ofMain.h"
#include "ofxFaceTracker2.h"

class PastSquare
{
public:
    PastSquare(ofVideoGrabber grabber, ofPixels frameToShowPixels, int pastSquareIndex, bool bgCaptured, ofxFaceTracker2 &tracker);
    ~PastSquare();
    
    void setup();
    void update();
    void draw(bool go, ofVideoGrabber grabber);
    void blur(bool go, ofVideoGrabber grabber);
    
    ofPixels squarePix;
    ofPixels squarePixMirrored;
    ofPixels currentPix;
    ofRectangle pastSquare;
    ofTexture pastSquareTexture;
    
    int pastSquareIndex;
    
    int direction;
    int dirCounter = 0;
    int goingLeft = 0;
    int goingRight = 1;
};
