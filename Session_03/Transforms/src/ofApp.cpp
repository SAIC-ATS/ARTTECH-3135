#include "ofApp.h"

void ofApp::setup()
{
    ofBackground(0);
}


void ofApp::draw()
{
    ofPushMatrix();

    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofDrawAxis(100);

//        ofSetColor(255, 255, 0);
//        ofDrawLine(0, 0, 100, 0);
//
//        ofPushMatrix();
//            ofTranslate(100, 0);
//            ofRotateZDeg(20);
//            ofSetColor(255, 255, 0);
//            ofDrawLine(0, 0, 100, 0);
//        ofPopMatrix();

    ofPopMatrix();

//
//    ofSetColor(255);
//    ofDrawRectangle(0, 0, 30, 30);
}
