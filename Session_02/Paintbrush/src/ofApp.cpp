#include "ofApp.h"


void ofApp::setup()
{
    // Set the background color.
    ofBackground(255);

    // Turn off auto background update.
    ofSetBackgroundAuto(false);

}


void ofApp::draw()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    float mx = ofGetMouseX();
    float my = ofGetMouseY();

    // Draw a semi-transparent black rectangle.
    ofSetColor(255, 20);
    ofDrawRectangle(0, 0, w, h);


    // Our brush begins here.
    int alpha = 40;

    float offset = 20;
    float radius = ofMap(mx, 0, w, 30, 80);

    ofSetColor(255, 0, 0, alpha);
    ofDrawCircle(mx - offset, my - offset, radius);

    ofSetColor(0, 255, 0, alpha);
    ofDrawCircle(mx + offset, my - offset, radius);

    ofSetColor(255, 255, 0, alpha);
    ofDrawCircle(mx + offset, my + offset, radius);

    ofSetColor(0, 0, 255, alpha);
    ofDrawCircle(mx - offset, my + offset, radius);

    // Our brush ends here.
}
