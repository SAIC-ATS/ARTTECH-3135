#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(ofColor::black);
    
    float xLineDistance = 8;
    
    for(float x = 0; x < ofGetWidth(); x+= xLineDistance){
        ofDrawLine(x, 0, x, ofGetHeight());
    }
    
    ofNoFill();
    ofSetColor(ofColor::white);
    
    float height = ofGetHeight() * 0.9;
    
    float topWidth = ofGetWidth() * 0.5;
    
    float bottomWidth = ofGetWidth() * 0.9;
    
    float middleX = ofGetWidth()/2;
    
    float middleY = ofGetHeight()/2;
    
    float topY = middleY - height/2;
    
    float bottomY = middleY + height/2;
    
    glm::vec2 p0(middleX - topWidth/2, topY);
    
    glm::vec2 p1(middleX + topWidth/2, topY);
    
    glm::vec2 p2(middleX + bottomWidth/2, bottomY);
    
    glm::vec2 p3(middleX - bottomWidth/2, bottomY);
    
    ofPath trapezoidMask;
    
    trapezoidMask.setFillColor(ofColor::black);
    
    trapezoidMask.rectangle(0,0,ofGetWidth(),ofGetHeight());
    
    trapezoidMask.moveTo(p0);
    
    trapezoidMask.lineTo(p1);
    trapezoidMask.lineTo(p2);
    trapezoidMask.lineTo(p3);
    trapezoidMask.lineTo(p0);
    
    trapezoidMask.draw();
    
    ofDrawLine(p0,p1);
    ofDrawLine(p1,p2);
    ofDrawLine(p2,p3);
    ofDrawLine(p3,p0);
    
}
