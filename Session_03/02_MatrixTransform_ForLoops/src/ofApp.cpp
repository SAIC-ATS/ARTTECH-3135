#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::update()
{
    angleDeg += 1;
}


void ofApp::draw()
{
    ofPushMatrix();
//    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2); // Translate the origin to the middle of the screen.
    ofTranslate(ofGetMouseX(), ofGetMouseY()); // Translate the origin to the middle of the screen.

    // Rotate everything after this.
    ofRotateZDeg(angleDeg);
    
    drawFlowerOfFlowers();
    
    for (float angle = 0; angle < 360; angle += 45)
    {
        ofPushMatrix();
        ofRotateZDeg(angle + angleDeg);
        ofTranslate(150, 0);
        drawFlowerOfFlowers();
        ofPopMatrix();
    }
    
    ofPopMatrix();
}


void ofApp::drawFlower()
{
    ofPushMatrix();
    
        ofSetColor(ofColor::green);
        ofDrawLine(0, 0, 100, 0);
    
        // Move to the end of the "stem".
        ofTranslate(100, 0);
    
        ofSetColor(ofColor::yellow);
        ofDrawCircle(0, 0, 15);
    
    ofPopMatrix();
}


void ofApp::drawFlowerOfFlowers()
{
    for (float angleDeg = 0; angleDeg < 360; angleDeg += 20)
    {
        ofPushMatrix();
        ofRotateZDeg(angleDeg);
        drawFlower();
        ofPopMatrix();
    }
}
