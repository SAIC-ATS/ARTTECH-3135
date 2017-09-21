#include "ofApp.h"


void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);

    // Get whichever one is biggest.
    int size = std::max(ofGetWidth(), ofGetHeight());

    // Ahhh, but this doesn't work if `i` isn't a nice multiple of width.
    for (int i = 0; i < 2 * size; i += 7)
    {
        ofDrawLine(0, i, i, 0);
    }
}













