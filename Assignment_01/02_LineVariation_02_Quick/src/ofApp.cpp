#include "ofApp.h"


void ofApp::draw()
{
    // Make black background.
    ofBackground(0);

    // Set the draw color and fill.
    ofNoFill();
    ofSetColor(255);

    // Set a few helpful variables.
    float lineSpacing = 16;
    float width = 512;
    float height = 512;

    // We start at -width and go to width to cover all.
    for (float x = -width; x <= width; x += lineSpacing)
    {
        ofDrawLine(x, 0, x + width, height);
    }

    // Draw a triangle mask!
    ofFill();
    ofSetColor(0);
    ofDrawTriangle(0, 0, width, 0, 0, height);

    ofNoFill();
    ofSetColor(255);
    // We start at -width and go double width to cover all.
    for (float x = 0; x <= width; x += lineSpacing)
    {
        ofDrawLine(x, 0, x - width, height);
    }
}
