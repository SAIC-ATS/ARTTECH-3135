#include "ofApp.h"


void ofApp::draw()
{
    // Set the background to 0 (black).
    ofBackground(0);

    // Set the drawing color to white.
    ofSetColor(255);

    // Draw vertical lines every 5 pixels while 'x' is less than the window width.
    for (float x = 0; x < ofGetWidth(); x += 5)
    {
        ofDrawLine(x, 0, x, ofGetHeight());
    }

    // Draw horizontal lines every 5 pixels while 'y' is less than the window height.
    for (float y = 0; y < ofGetHeight(); y += 5)
    {
        ofDrawLine(0, y, ofGetWidth(), y);
    }
}

