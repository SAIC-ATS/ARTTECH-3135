#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(0);

    ofSetBackgroundAuto(false);

    image0.load("gradient.png");
    image1.load("puppy_1.jpg");
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());


//    ofSetColor(255, 255, 0);
//    image0.draw(0, 0);
//    image1.draw(ofGetMouseX(), ofGetMouseY());

    ofEnableBlendMode(OF_BLENDMODE_ADD);

    ofSetColor(255);
    for (int i = 0; i < 50; i++)
    {
        float hue = ofRandom(0, 255);
        ofSetColor(ofColor::fromHsb(hue, 255, 255));

        float x = ofRandom(0, ofGetWidth());
        float y = ofRandom(0, ofGetHeight());

        float size = ofRandom(10, 100);


        image0.draw(x, y, size, size);
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
