#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
}


void ofApp::draw()
{
    float xIncrement = 0.01;
    float xOffset = 0;

    for (int x = 0; x < ofGetWidth(); x++)
    {
        xOffset += xIncrement;

        float noise = ofNoise(xOffset);
        float hue = ofMap(noise, 0, 1, 0, 255);
        ofSetColor(ofColor::fromHsb(hue, 255, 255));
        ofDrawLine(x, 0, x, ofGetHeight());
    }
}
