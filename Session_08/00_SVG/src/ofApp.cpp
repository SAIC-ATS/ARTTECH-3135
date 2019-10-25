#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::update()
{
}


void ofApp::draw()
{
    if (drawOneFrame)
    {
        ofBeginSaveScreenAsSVG("output.svg");
    }

    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    for (float angle = 0; angle < 360; angle += 20)
    {
        float gray = ofMap(angle, 0, 360, 0, 255, true);
        
        ofSetColor(gray);
        
        ofPushMatrix();
        ofRotateZDeg(angle);
        ofDrawRectangle(100, 0, 100, 200);
        ofPopMatrix();
    }
    ofPopMatrix();
    
    // Any drawing commands between these two functions
    // will be rendered to an svg file.
    
    if (drawOneFrame)
    {
        ofEndSaveScreenAsSVG();
    }


    // Since I completed my drawing, set it to false.
    if (drawOneFrame)
    {
        drawOneFrame = false;
    }
}


void ofApp::keyPressed(int key)
{
    drawOneFrame = true;
}
