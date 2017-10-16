#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
}


void ofApp::update()
{
    xOffset += xIncrement;
}


void ofApp::draw()
{
    float noiseValue = ofNoise(xOffset);  // Always returns a value between 0 and 1.
    float angle = ofMap(noiseValue, 0, 1, 0, 360);

    ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateZDeg(angle);
        ofSetColor(ofColor::yellow);
        ofDrawLine(0, 0, 400, 0);
    ofPopMatrix();


    float otherNoiseValue = ofNoise(xOffset + 400);  // Always returns a value between 0 and 1.
    float otherAngleAngle = ofMap(otherNoiseValue, 0, 1, 0, 360);

    ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateZDeg(otherAngleAngle);
        ofSetColor(ofColor::red);
        ofDrawLine(0, 0, 400, 0);
    ofPopMatrix();
}
