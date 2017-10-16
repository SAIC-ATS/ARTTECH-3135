#include "ofApp.h"


void ofApp::draw()
{
    for (int x = 0; x < ofGetWidth(); x++)
    {
        int grayscaleValue = ofWrap(x, 0, 255);
        // int grayscaleValue = ofMap(x, 0, ofGetWidth(), 0, 255);
        ofSetColor(grayscaleValue);
        ofDrawLine(x, 0, x, ofGetHeight());
    }
}


