#include "ofApp.h"


void ofApp::draw()
{
    // Set the background to 0 (black).
    ofBackground(0);

    // A sequence of lines can each drawn one by one.
    // ofDrawLine(0, 0, 0, ofGetHeight());
    // ofDrawLine(5, 0, 5, ofGetHeight());
    // ofDrawLine(10, 0, 10, ofGetHeight());
    // ofDrawLine(15, 0, 15, ofGetHeight());
    // ofDrawLine(20, 0, 20, ofGetHeight());
    // ofDrawLine(25, 0, 25, ofGetHeight());
    // ofDrawLine(30, 0, 30, ofGetHeight());
    // ofDrawLine(35, 0, 35, ofGetHeight());

    // ... and so on.

    // OR ... we can use a loop.

    ofSetColor(255);

    // Draw lines every 5 pixels while 'x' is less than the window width.
    for (float x = 0; x < ofGetWidth(); x += 5)
    {
        ofDrawLine(x, 0, x, ofGetHeight());
    }
}
