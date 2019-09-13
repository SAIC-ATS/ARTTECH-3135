#include "ofApp.h"


void ofApp::draw()
{
    // Make black background.
    ofBackground(0);

    // Set a few helpful variables.
    float initialLineSpacing = 1;
    float width = 512;
    float height = 512;

    // We start at -width and go double width to cover all.
    for (float x = initialLineSpacing; x <= width; x *= 2)
    {
        ofDrawLine(x, 0, x - width, height);
    }
}
