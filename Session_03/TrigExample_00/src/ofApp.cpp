#include "ofApp.h"

void ofApp::setup()
{
    ofBackground(0);
}


void ofApp::draw()
{
    float angleDeg = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 360);

    float radius = 200;

    float xOrigin = ofGetWidth() / 2;
    float yOrigin = ofGetHeight() / 2;

    float x = radius * cos(ofDegToRad(angleDeg)) + xOrigin;
    float y = radius * sin(ofDegToRad(angleDeg)) + yOrigin;

    ofDrawLine(xOrigin, yOrigin, x, y);

}
