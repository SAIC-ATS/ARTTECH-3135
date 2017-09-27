#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(255);
    myFace.setup();
}


void ofApp::draw()
{
//    ofPushMatrix();
//    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    myFace.draw();
//    ofPopMatrix();
}













