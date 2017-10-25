#include "ofApp.h"


void ofApp::setup()
{
    fbo0.allocate(640, 480);
    fbo1.allocate(640, 480);
}


void ofApp::update()
{
}


void ofApp::draw()
{
    fbo0.begin();
    ofClear(255, 255, 255, 0);
    ofFill();
    ofSetColor(127);
    ofDrawRectangle(0, 0, fbo0.getWidth(), fbo0.getHeight());
    ofSetColor(ofColor::red);
    ofFill();
    ofDrawRectangle(0, 0, ofRandom(100), ofRandom(100));
    fbo0.end();


    for (int i = 0; i < 360; i += 100)
    {
        ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateZDeg(i);
        fbo0.draw(0, 0);
        ofPopMatrix();
    }

}

