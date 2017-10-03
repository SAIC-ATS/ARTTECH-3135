#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    xOffset += xIncrement;
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int x = 0; x < ofGetWidth(); x++)
    {
        float moreOffsets = ofMap(x, 0, ofGetWidth(), 0, 0.3);
        float noise = ofNoise(xOffset + moreOffsets);
        float hue = ofMap(noise, 0, 1, 0, 255);
        ofSetColor(ofColor::fromHsb(hue, 255, 255));
        ofDrawLine(x, 0, x, ofGetHeight());
    }
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
