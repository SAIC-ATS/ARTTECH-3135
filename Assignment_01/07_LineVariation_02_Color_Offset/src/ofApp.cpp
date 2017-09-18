#include "ofApp.h"


void ofApp::draw()
{
    // Make black background.
    ofBackground(0);

    // Set the draw color and fill.
    ofNoFill();

    // Set a few helpful variables.
    float lineSpacing = 4;
    float width = 512;
    float height = 512;


    // We start at -width and go to width to cover all.
    for (float x = -width; x <= width; x += lineSpacing)
    {
        float grayscale = ofMap(x, -width, width, 0, 255);
        ofSetColor(grayscale);
        ofDrawLine(x, 0, x + width, height);
    }

    // Draw a triangle mask!
    ofFill();
    ofSetColor(0);
    ofDrawTriangle(0, 0, width, 0, 0, height);

    ofNoFill();

    hueOffset = ofWrap(hueOffset + 1, 0, 255);

    // We start at -width and go double width to cover all.
    for (float x = 0; x <= width; x += lineSpacing)
    {
        float hue = ofMap(x, 0, width, 0, 255);
        hue = ofWrap(hue + hueOffset, 0, 255);;

        ofSetColor(ofColor::fromHsb(hue, 255, 255));
        ofDrawLine(x, 0, x - width, height);
    }
}
