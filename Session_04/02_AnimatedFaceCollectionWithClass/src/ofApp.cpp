#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(255);

    for (int i = 0; i < 25; i++)
    {
        Face theFace;
        theFace.setup();
        theFace.headColor = ofColor::fromHsb(ofRandom(255), 255, 255);
        theFace.mouthHeight = ofRandom(10, 20);
        theFace.mouthWidth = ofRandom(10, 80);

        myFaces.push_back(theFace);
    }
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(100, 100);
    for (int i = 0; i < myFaces.size(); i++)
    {
        float x = i / 5;
        float y = i % 5;

        ofPushMatrix();
        ofTranslate(x * 200, y * 200);
        myFaces[i].draw();
        ofPopMatrix();
    }
    ofPopMatrix();
}

