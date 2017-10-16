#include "ofApp.h"


void ofApp::draw()
{
    int lineIndex = 0;

    for (int x = 0; x < ofGetWidth(); x += 10)
    {
        if (lineIndex % 2 == 0)
        {
            ofSetColor(ofColor::black);
        }
        else
        {
            ofSetColor(ofColor::red);
        }

        lineIndex++;

        ofDrawLine(x, 0, x, ofGetHeight());
    }
}


