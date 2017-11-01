#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    targetX = ofRandom(100,ofGetWidth()/2);
    targetY = ofRandom(100,ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::update(){
    randomCycle();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetColor(0,0,0,10);
    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    int red = ofMap(ofGetMouseX(),0,ofGetWidth(),0,255);
    int blue = ofMap(ofGetMouseY(),0,ofGetHeight(),0,255);

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    //outer circles
    ofSetColor(red,blue,counter, 200);
    ofDrawEllipse(200*cos(ofGetFrameNum()), 200*sin(ofGetFrameNum()), randX, randY);
    
    //middle circles
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(counter,blue,red, 200);
    ofDrawEllipse(100*cos(ofGetFrameNum()), 100*sin(ofGetFrameNum()), randY, randX);
    
    //inner circle
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(blue,counter,red, 200);
    ofDrawEllipse(sin(counter), cos(counter), randX*sin(counter), randY*sin(counter));
}

void ofApp::randomCycle(){
    if(colorUp){
        counter++;
        if(counter >= 255){
            colorUp = false;
        }
    }
    else {
        counter--;
        if(counter <= 0){
            colorUp = true;
        }
    }
    
    if(randX == targetX){
        targetX = (int)ofRandom(0,ofGetWidth()/2);
    }
    else if(randY == targetY){
        targetY = (int)ofRandom(0,ofGetHeight()/2);
    }
    
    if(targetX > randX){
        randX++;
    }
    else if (targetX < randX){
        randX--;
    }

    if(targetY > randY){
        randY++;
    }
    else if(targetY < randY){
        randY--;
    }
}
