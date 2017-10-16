#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(255);

    myOtherFace.headColor = ofColor::yellow;
    myOtherFace.mouthHeight = 10;
    myOtherFace.mouthWidth = 10;

}


void ofApp::update()
{
    // Here we call the 
    myFace.update();
    myOtherFace.update();
}

void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(ofGetWidth() * 0.33, ofGetHeight() * 0.33);
    myFace.draw();
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(ofGetWidth() * 0.66, ofGetHeight() * 0.66);
    myOtherFace.draw();
    ofPopMatrix();
}













