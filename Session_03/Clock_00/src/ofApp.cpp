#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    float secs = ofGetSeconds();
    float mins = ofGetMinutes();
    float hours = ofGetHours();

    float sAngle = ofMap(secs, 0, 60, 0, 360);
    float mAngle = ofMap(mins, 0, 60, 0, 360);
    float hAngle = ofMap(hours, 0, 24, 0, 720);

    float sLength = 400;
    float mLength = 300;
    float hLength = 200;

    ofColor sColor = ofColor::red;
    ofColor mColor = ofColor::blue;
    ofColor hColor = ofColor::green;

    float w = ofGetWidth();
    float h = ofGetHeight();


    ofPushMatrix();
        ofTranslate(w / 2, h / 2); // Move to the middle of the screen.
        ofRotateZDeg(-90); // Rotate to look more like a clock face.

        ofPushMatrix();
            ofRotateZDeg(sAngle);
            ofSetColor(sColor);
            ofDrawLine(0, 0, sLength, 0);
        ofPopMatrix();

        ofPushMatrix();
            ofRotateZDeg(mAngle);
            ofSetColor(mColor);
            ofDrawLine(0, 0, mLength, 0);
        ofPopMatrix();

        ofPushMatrix();
            ofRotateZDeg(hAngle);
            ofSetColor(hColor);
            ofDrawLine(0, 0, hLength, 0);
        ofPopMatrix();

    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
