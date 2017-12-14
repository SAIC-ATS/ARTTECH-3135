#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::update(){
    xOffset += xIncrement;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float noiseValue = ofNoise(xOffset);  // Always returns a value between 0 and 1.
    float angle = ofMap(noiseValue, 0, 1, 0, 360);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateZDeg(angle);
    int r = ofRandom(255);
    int g = ofRandom(255);
    int b = ofRandom(255);
    int o = ofRandom(255);
    ofSetColor(136, 232, 181, 50);
    ofDrawCircle(0, 0, 100);
    
    float otherNoiseValue = ofNoise(xOffset + 400);  // Always returns a value between 0 and 1.
    float otherAngleAngle = ofMap(otherNoiseValue, 0, 1, 0, 360);
    
    ofSetColor(194, 157, 242, 100);
    float xPos = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, ofGetWidth());
    ofDrawCircle(xPos, 200, 50);
    ofSetColor(ofColor::cornflowerBlue, 100);
    ofDrawTriangle(xPos, 0, 0, 30, xPos + 20, 0);
    float yPos = ofMap(cos(ofGetElapsedTimef()), -1, 1, 0, ofGetWidth());
    if (ofGetFrameNum() % 5 == 0){
        ofSetColor(r, 0, b, 255);
        ofDrawRectangle(0, yPos, 20, yPos + 20);
    }
    ofPopMatrix();
  
}

//--------------------------------------------------------------