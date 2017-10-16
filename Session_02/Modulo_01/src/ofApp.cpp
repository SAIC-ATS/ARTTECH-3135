#include "ofApp.h"


void ofApp::draw()
{
    int lineIndex = 0;

    for (int x = 0; x < ofGetWidth(); x += 10)
    {
        if (lineIndex % 3 == 0)
        {
            ofSetColor(ofColor::black);
        }
        if (lineIndex % 3 == 1)
        {
            ofSetColor(ofColor::green);
        }
        else if (lineIndex % 3 == 2)
        {
            ofSetColor(ofColor::red);
        }

        lineIndex++;

        ofDrawLine(x, 0, x, ofGetHeight());
    }
}


