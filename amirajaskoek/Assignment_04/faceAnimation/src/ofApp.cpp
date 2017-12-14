#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(255);
    
    for (int i = 0; i < 16; i++)
    {
        Face theFace;
        theFace.setup();
        theFace.headColor = ofColor::fromHsb(ofRandom(255), 255, 255);
        theFace.noseColor = ofColor::fromHsb(ofRandom(255), 255, 255);
        
        myFaces.push_back(theFace);
    }
}


void ofApp::update()
{
    for (std::size_t i = 0; i < myFaces.size(); i++)
    {
        myFaces[i].update();
    }
}


void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(100, 100);
    for (std::size_t i = 0; i < myFaces.size(); i++)
    {
        float x = i / 4;
        float y = i % 4;
        
        ofPushMatrix();
        ofTranslate(x * 220, y * 220);
        myFaces[i].draw();
        ofPopMatrix();
    }
    ofPopMatrix();
}