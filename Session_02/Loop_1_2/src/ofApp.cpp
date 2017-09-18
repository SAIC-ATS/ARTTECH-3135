#include "ofApp.h"


void ofApp::setup()
{
    offsetX = ofGetWidth() / 2;
    offsetY = ofGetHeight() / 2;
}


void ofApp::update()
{
    angle = angle + angleIncrementDegrees;
    angle2 = angle2 + angleIncrementDegrees2;
}


void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);

    // Move our canvas (translate)

    ofPushMatrix();
    ofTranslate(offsetX, offsetY);
    ofRotateZ(angle);

    //drawGrid();

    ofDrawCircle(0, 0, 10);
    ofDrawLine(0, 0, radius, 0);
    ofDrawCircle(radius, 0, 10);

    ofTranslate(radius, 0);
    ofRotateZ(angle2);
    ofDrawCircle(0, 0, 10);
    ofDrawLine(0, 0, radius, 0);
    ofDrawCircle(radius, 0, 10);

    ofPopMatrix();

    ofDrawRectangle(0, 0, 10, 10);
}


void ofApp::drawGrid()
{
    for (int x = 0; x < ofGetWidth(); x += 25)
    {
        ofDrawLine(x, 0, x, ofGetHeight());
    }

    for (int y = 0; y < ofGetHeight(); y += 25)
    {
        ofDrawLine(0, y, ofGetWidth(), y);
    }

    ofNoFill();

    ofDrawAxis(<#float size#>)
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}













