#include "ofApp.h"


void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(255);
}

void ofApp::draw()
{
    if (ofGetKeyPressed('c'))
    {
        ofClear(255);
    }

    // 1. List all of the variables that I want to control with user input.
    float radius = 0;
    float offset = 0;

    float mx = ofGetMouseX();
    float my = ofGetMouseY();

    float w = ofGetWidth();
    float h = ofGetHeight();

    // 2. Read or listen to the user input and set all of the variables to the right values based on that input.
    radius = ofMap(mx, 0, w, 20, 50);
    offset = ofMap(my, 0, h, 10, 100);

    // 3. Draw all of your output using the variables from section 1.

    ofSetColor(ofColor::lightGreen);
    ofDrawCircle(mx + offset, my - offset, radius);

    ofSetColor(ofColor::yellow);
    ofDrawCircle(mx + offset, my + offset, radius);

    ofSetColor(ofColor::orange);
    ofDrawCircle(mx - offset, my + offset, radius);

    ofSetColor(ofColor::red);
    ofDrawCircle(mx - offset, my - offset, radius);

}


