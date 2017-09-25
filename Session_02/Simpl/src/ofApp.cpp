#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    // 1. List all of the variables that I want to control with user input.


    // 2. Read or listen to the user input and set all of the variables to the right values based on that input.


    // 3. Draw all of your output using the variables from section 1.



//    if (ofGetKeyPressed('j'))
//    {
//        ofDrawRectangle(0, 0, 100, 100);
//    }
//
//
//    if (ofGetMousePressed())
//    {
//        ofDrawRectangle(100, 100, 100, 100);
//    }
//    else if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT))
//    {
//        ofDrawRectangle(200, 200, 100, 100);
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    std::cout << "The " << key << " key was pressed." << std::endl;

    // Don't draw from anywhere except the draw() function!
    // ofDrawRectangle(0, 0, 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    std::cout << "The " << key << " key was released." << std::endl;
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
