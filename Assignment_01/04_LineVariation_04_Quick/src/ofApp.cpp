#include "ofApp.h"


void ofApp::draw()
{
    // Make black background.
    ofBackground(0);

    // Set a few helpful variables.
    float initialLineSpacing = 1;
    float width = 512;
    float height = 512;

    ofNoFill();
    ofSetColor(255);
    // We start at -width and go double width to cover all.
    for (float x = initialLineSpacing; x <= width; x *= 2)
    {
        ofDrawLine(width - x, 0, 2 * width - x, height);
    }

    // Draw a triangle mask!
    ofFill();
    ofSetColor(0);
    ofDrawTriangle(0, 0, width, 0, 0, height);

    ofNoFill();
    ofSetColor(255);
    // We start at -width and go double width to cover all.
    for (float x = initialLineSpacing; x <= width; x *= 2)
    {
        ofDrawLine(x, 0, x - width, height);
    }

}
