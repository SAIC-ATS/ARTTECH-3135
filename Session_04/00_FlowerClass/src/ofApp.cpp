#include "ofApp.h"


void ofApp::setup()
{
    ofSetCircleResolution(64);
    
//    myFlower.centerColor = ofColor::purple;
//    myFlower.petalColor = ofColor(255, 0, 0, 80);
//    myFlower.centerRadius = 10;
//    myFlower.petalLength = 100;
//    myFlower.numberOfPetals = 60;
//
//
//    myOtherFlower.numberOfPetals = 100;
    
}


void ofApp::update()
{
}


void ofApp::draw()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    //ofDrawLine(w/2, 0, w/2, h);
    //ofDrawLine(0, h/2, w, h/2);
    
    ofPushMatrix();
    ofTranslate(w / 4, h / 4);
    myFlower.draw();

    ofTranslate(w / 4, h / 4);
    myOtherFlower.draw();
    
    ofTranslate(w / 4, h / 4);
    myOtherFlowerAgain.draw();

    ofPopMatrix();
}
