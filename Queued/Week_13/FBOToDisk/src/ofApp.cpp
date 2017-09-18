#include "ofApp.h"


void ofApp::setup()
{
    fbo.allocate(ofGetWidth(), ofGetHeight());
}


void ofApp::update()
{
    position += 1;

    if (position > ofGetWidth())
    {
        position = 0;
    }
}


void ofApp::draw()
{
    fbo.begin();
    ofClear(0, 0, 0);

    ofFill();
    ofSetColor(0, 127);
    ofDrawEllipse(ofGetWidth() / 2, position, 10, 10);

    fbo.end();

    fbo.draw(0, 0);
    
}


void ofApp::keyPressed(int key)
{
    ofPixels pixels;
    fbo.readToPixels(pixels);
    ofSaveImage(pixels, ofGetTimestampString() + "_image.png");
}
