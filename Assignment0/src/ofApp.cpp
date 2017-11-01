#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::black);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //On a black wall, a white circle within which are white vertical parallel lines, and a white parallelogram within which are white horizontal parallel lines. The vertical lines within the circle do not enter the parallelogram, and the horizontal lines within the parallelogram do not enter the circle.
    
    ofSetColor(ofColor::white);
    ofNoFill();
    
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 300);
    
    int circleLineSpace = 10;
    
    for(int i = 0; i<ofGetWidth(); i+=circleLineSpace){
        ofDrawLine(i, 0, i, ofGetHeight());
    }
    
    ofPath circleMask;
    
    circleMask.setFillColor(ofColor::black);
    circleMask.rectangle(0, 0, ofGetWidth(), ofGetHeight());
    circleMask.setCircleResolution(64);
    circleMask.circle(ofGetWidth()/2, ofGetHeight()/2, 300);
    circleMask.draw();
    
    ofSetCircleResolution(64);
    
//    //p0, p1
//    ofDrawLine(ofGetWidth()/4, ofGetHeight()/2, ofGetWidth()*2/3, ofGetHeight()*2/3);
//    //p2, p3
//    ofDrawLine(ofGetWidth()/4+50, ofGetHeight()/2+75, ofGetWidth()*2/3+40, ofGetHeight()*2/3 + 75);
//    ofDrawLine(ofGetWidth()/4, ofGetHeight()/2, ofGetWidth()/4+50, ofGetHeight()/2+75);
//    ofDrawLine(ofGetWidth()*2/3, ofGetHeight()*2/3, ofGetWidth()*2/3+40, ofGetHeight()*2/3 + 75);
//    
//    ofPath parallelogram;
//    parallelogram.setFillColor(ofColor::black);
//    parallelogram.setStrokeColor(ofColor::white);
//    parallelogram.setFilled(true);
//    parallelogram.setStrokeWidth(1);
//    parallelogram.moveTo(ofGetWidth()/4, ofGetHeight()/2);
//    parallelogram.lineTo(ofGetWidth()/4+50, ofGetHeight()/2+75);
//    parallelogram.lineTo(ofGetWidth()*2/3+40, ofGetHeight()*2/3 + 75);
//    parallelogram.lineTo(ofGetWidth()*2/3, ofGetHeight()*2/3);
//    parallelogram.lineTo(ofGetWidth()/4, ofGetHeight()/2);
//    parallelogram.draw();
//
//    int paraLineSpace = 10;
    
    
//    for (float y = topY; y < bottomY; y += yLineDistance)
//    {
//        float xStart = ofMap(y, topY, bottomY, p0.x, p3.x);
//        
//        ofVec2f lineStart(xStart, y);
//        ofVec2f lineEnd(xStart + width, y);
//        ofDrawLine(lineStart, lineEnd);
//    }
    
//    for(int i = 0; i<ofGetWidth(); i+=paraLineSpace){
//        ofDrawLine(0, i, ofGetWidth(), i);
//    }
    
    // The parallelogram width (see diagram).
    float width = 320;
    
    // The parallelogram width (see diagram).
    float height = 320;
    
    // The parallelogram offset (see diagram).
    float offset = 40;
    
    // The y-position of the top line.
    float topY = (ofGetHeight() / 2) - height / 2;
    
    // The y-position of the bottom line.
    float bottomY = (ofGetHeight() / 2) + height / 2;
    
    // The point p0.
    ofVec2f p0((ofGetWidth() / 2) - width / 2 + offset, topY);
    
    // The point p1.
    ofVec2f p1((ofGetWidth() / 2) + width / 2 + offset, topY);
    
    // The point p0.
    ofVec2f p2((ofGetWidth() / 2) + width / 2 - offset, bottomY);
    
    // The point p1.
    ofVec2f p3((ofGetWidth() / 2) - width / 2 - offset, bottomY);
    
    // Construct and draw a paralellogram.
    ofPath parallelogram;
    parallelogram.setFillColor(ofColor::black);
    parallelogram.setStrokeColor(ofColor::white);
    parallelogram.setFilled(true);
    parallelogram.setStrokeWidth(1);
    parallelogram.moveTo(p0);
    parallelogram.lineTo(p1);
    parallelogram.lineTo(p2);
    parallelogram.lineTo(p3);
    parallelogram.lineTo(p0);
    parallelogram.draw();
    
    // Set the distance between the horizontal parallel lines.
    float yLineDistance = 8;
    
    for (float y = topY; y < bottomY; y += yLineDistance)
    {
        float xStart = ofMap(y, topY, bottomY, p0.x, p3.x);
        
        ofVec2f lineStart(xStart, y);
        ofVec2f lineEnd(xStart + width, y);
        ofDrawLine(lineStart, lineEnd);
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
