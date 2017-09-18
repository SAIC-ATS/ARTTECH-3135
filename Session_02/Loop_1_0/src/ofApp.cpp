#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);

    int width = ofGetWidth();

    // Ahhh, but this doesn't work if `i` isn't a nice multiple of width.
    for (int i = 0; i < width; i += 7)
    {
        ofDrawLine(0, i, i, 0);
        ofDrawLine(i, width, width, i);
    }
}













