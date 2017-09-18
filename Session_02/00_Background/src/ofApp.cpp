#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);

    // Turn off auto background update.
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // Draw a semi-transparent black rectangle.
    ofSetColor(255, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());


    /// our brush begins here
    int alpha = 40;

    // mouse position x
    float mx = ofGetMouseX();
    float my = ofGetMouseY();

    float offset = 20;
    float radius = ofMap(mx, 0, ofGetWidth(), 30, 80);

    ofSetColor(255, 0, 0, alpha);
    ofDrawCircle(mx - offset, my - offset, radius);

    ofSetColor(0, 255, 0, alpha);
    ofDrawCircle(mx + offset, my - offset, radius);


    ofSetColor(255, 255, 0, alpha);
    ofDrawCircle(mx + offset, my + offset, radius);


    ofSetColor(0, 0, 255, alpha);
    ofDrawCircle(mx - offset, my + offset, radius);



    /// our brush ends here
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
