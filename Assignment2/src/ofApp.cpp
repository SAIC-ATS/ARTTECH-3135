#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(255);
    
    ofSetBackgroundAuto(false);
    
    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
}

//--------------------------------------------------------------
void ofApp::update()
{

    for(auto it = blobList.begin(); it != blobList.end(); ++it)
    {
        it->grow();
        // disable move for cleaner bacteria thing
//        it->move();
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0,10);
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    int count = 0;
    
    for(auto it = blobList.begin(); it != blobList.end(); ++it)
    {
        count++;
        ofSetColor(ofColor::fromHsb(it->hue, 255, 255, it->a));
        ofDrawEllipse(it->x, it->y, it->width, it->height);
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    Blob newBlob = Blob();
    
    newBlob.x = x;
    newBlob.y = y;
    
    blobList.push_back(newBlob);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    Blob newBlob = Blob();
    
    newBlob.x = x;
    newBlob.y = y;
    newBlob.a = 100;
    newBlob.width = 5;
    newBlob.height = 25;
    
    blobList.push_back(newBlob);
}

