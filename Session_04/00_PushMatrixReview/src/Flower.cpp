#include "ofApp.h"


void ofApp::draw()
{
    float w = ofGetWidth();
    float h = ofGetHeight();

    ofBackground(80);
    ofFill();
    
    ofSetColor(ofColor::red, 100);
    ofDrawRectangle(0, 0, 100, 200);
    
    // ofSetColor(ofColor::green, 100);
    // ofDrawRectangle(w / 4, h / 4, 100, 200);

    // "Save the current frame of reference ... "transformation matrix"
    // This frame of referece is called "base"
    ofPushMatrix();
    {
        ofTranslate(w / 3, h / 3);
        
        ofFill();
        
        ofSetColor(ofColor::orange, 100);
        ofDrawRectangle(0, 0, 100, 200);
        
        // ofSetColor(ofColor::black, 100);
        // ofDrawRectangle(w / 4, h / 4, 100, 200);
        
        
        ofPushMatrix(); // transform_2
        {
            ofTranslate(30, 30);
            
            ofFill();
            ofSetColor(ofColor::pink, 100);
            ofDrawRectangle(0, 0, 100, 200);
            
            
            ofPushMatrix();
            {
                ofRotateZDeg(45);
                ofFill();
                ofSetColor(ofColor::yellowGreen, 100);
                ofDrawRectangle(0, 0, 100, 200);
            }
            ofPopMatrix();
            
//            ofSetColor(ofColor::blue);
//            ofDrawRectangle(0, 0, w, h);
            
        }
        ofPopMatrix(); // return the state before transform_2
        
        
        ofFill();
        ofSetColor(ofColor::deepSkyBlue, 100);
        ofDrawRectangle(0, 0, 20, 20);
        
    }
    ofPopMatrix(); // returning to the the "base" frame of reference.
    
    ofFill();
    ofSetColor(ofColor::deepPink, 100);
    ofDrawRectangle(0, 0, 20, 20);
}

