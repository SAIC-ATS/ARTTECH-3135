#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);

    offsetX = ofGetWidth() / 2;
    offsetY = ofGetHeight() / 2;
}


void ofApp::update()
{
    angle = angle + angleIncrementDegrees;
}


void ofApp::draw()
{
    ofSetColor(ofColor::white);

    // Move our canvas (translate)

    ofPushMatrix();
    ofTranslate(offsetX, offsetY);
    ofRotateZDeg(angle);

    drawGrid();

    ofSetColor(255, 0, 0);
    ofDrawCircle(0, 0, 10);
    ofDrawLine(0, 0, radius, 0);
    ofDrawCircle(radius, 0, 10);

    ofDrawRectangle(100, 100, 20, 10);

    ofPopMatrix();
}


void ofApp::drawGrid()
{
    ofSetColor(127);

    for (int x = 0; x < ofGetWidth(); x += 25)
    {
        ofDrawLine(x, 0, x, ofGetHeight());
    }

    for (int y = 0; y < ofGetHeight(); y += 25)
    {
        ofDrawLine(0, y, ofGetWidth(), y);
    }

    ofNoFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}
