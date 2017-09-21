#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetBackgroundAuto(false);
}


void ofApp::draw()
{
    ofSetColor(0, 5);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    for (int i = 0; i < 100; i++)
    {
        float offsetX = ofRandom(-30, 30);
        float offsetY = ofRandom(-300, 300);

        float x = ofGetMouseX() + offsetX;
        float y = ofGetMouseY() + offsetY;

        float radius = ofRandom(3, 30);

        float grayscale = ofRandom(0, 255);

        ofSetColor(grayscale);
        ofDrawCircle(x, y, radius);
    }
}
