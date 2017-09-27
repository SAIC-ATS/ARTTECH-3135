#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(255);
    myFace.setup();


    myOtherFace.setup();
    myOtherFace.headColor = ofColor::yellow;
    myOtherFace.mouthHeight = 10;
    myOtherFace.mouthWidth = 10;

}


void ofApp::update()
{
    myOtherFace.mouthHeight = ofRandom(10, 20);
    myOtherFace.mouthWidth = ofRandom(10, 20);

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













