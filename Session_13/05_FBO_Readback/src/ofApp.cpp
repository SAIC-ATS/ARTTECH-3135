#include "ofApp.h"


void ofApp::setup()
{
    fbo.allocate(320, 240);
    fbo.begin();
    ofClear(0);
    fbo.end();
}


void ofApp::update()
{

}


void ofApp::draw()
{
    fbo.begin();
    ofClear(0);
    ofFill();
    ofSetColor(255);
    ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 30, 30);

    // tex.draw(0, 0);

    fbo.end();

    fbo.draw(0, 0);
}


void ofApp::applyPixelsToGOL(const ofPixels& pixels)
{
    // for ...
        // for ...
           // grid[c][r] = ....

}



void ofApp::keyPressed(int key)
{
    ofPixels p;
    fbo.readToPixels(p);
    applyPixelsToGOL(p);
}

