#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    flameBrush.load("flameBrush.png");
    star.load("star.png");
    gudetama.load("gudetama.png");
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(ofGetKeyPressed('e')){
        ofClear(255);
    }
    
    if(ofGetKeyPressed('c')){
        circleRotate();
    }
    
    if(ofGetKeyPressed('f')){
        flamesBrush();
    }
    
    if(ofGetKeyPressed('s')){
        starBrush();
    }
    
    if(ofGetKeyPressed('l')){
        lines();
    }
    
    if(ofGetKeyPressed('x')){
        eraser();
    }
    
    if(ofGetKeyPressed('r')){
        randomBoi();
    }
    if(ofGetKeyPressed('g')){
        gude();
    }
    
        
}

//--------------------------------------------------------------
void ofApp::circleRotate(){
    
    float mx = ofGetMouseX();
    float my = ofGetMouseY();
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    float radius = 0;
    float dist = 5;
    
    radius = ofMap(mx, 0, w, 50, 100);
    
    
    ofSetColor(0, ofGetMouseX(), ofGetMouseY());
    ofDrawCircle((mx + dist), (my - dist), radius);
    
    
}

//------------------------------------------------------------
void ofApp::flamesBrush(){
    
    float size = 0;
    size = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 300);
    
    for(int i= 0;i< ofGetMouseX(); i = i + 11){
        if(i % 2 ==0){
            ofSetColor(140, 184, 255);
        }
        else{
            ofSetColor(255, 140, 237);
        }
    }
    
    
    
    flameBrush.draw(ofGetMouseX(), ofGetMouseY(), size, size);
    
    
}

//-------------------------------------------------------------
void ofApp::starBrush(){
    
    for(int i = 0; i < ofGetMouseY(); i = i+ 10){
        if(i % 3 == 0){
            ofSetColor(255, 0, 0);
        }
        else if(i % 3 == 1){
            ofSetColor(0, 255, 0);
        }
        else{
            ofSetColor(0, 0, 255);
        }
    }
    
    
    star.draw(ofGetMouseX(),ofGetMouseY(),200, 200);

    
}

//------------------------------------------------------------
void ofApp::lines(){
    
    ofSetLineWidth(1);
    ofSetColor(0);
    ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX() + 5, ofGetMouseY() + 5);
    
}

//---------------------------------------------------------
void ofApp::eraser(){
    ofSetColor(255);
    ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 50);
    
}
//--------------------------------------------------------
void ofApp::randomBoi(){
    
    int r = ofRandom(0, 255);
    int g = ofRandom(0, 255);
    int b = ofRandom(0, 255);
    int o = ofRandom(0, 255);
    
    ofSetColor(r, g, b, o);
    ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 200, 200);
}
//-----------------------------------------------------
void ofApp::gude(){

    gudetama.draw(ofGetMouseX(), ofGetMouseY(), 200, 112);
    
}
//----------------------------------------------------------