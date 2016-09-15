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

    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    ofRotateZ(angle);
//    ofTranslate(ofGetWidth(), ofGetHeight());
//    ofRotateY(angle);

    for (int x = 0; x < ofGetWidth(); x += 50)
    {
        for (int y = 0; y < ofGetHeight(); y+= 50)
        {
            ofPushMatrix();
            ofTranslate(x, y);
            ofRotateZ(angle);

            //drawGrid();

            ofDrawCircle(0, 0, 2);
            ofDrawLine(0, 0, radius, 0);
            ofDrawCircle(radius, 0, 3);

            ofTranslate(radius, 0);
            ofRotateZ(angle2);
            ofDrawCircle(0, 0, 3);
            ofDrawLine(0, 0, radius, 0);
            ofDrawCircle(radius, 0, 3);
            
            ofPopMatrix();
        }
    }

    ofPopMatrix();

//    ofDrawRectangle(0, 0, 10, 10);
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
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}













