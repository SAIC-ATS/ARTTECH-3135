#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetBackgroundAuto(false);
    image0.load("gradient.png");
    image1.load("puppy_1.jpg");
}


void ofApp::draw()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    float mx = ofGetMouseX();
    float my = ofGetMouseY();

    ofSetColor(0, 10);
    ofDrawRectangle(0, 0, w, h);

    // Set the image tint to yellow.
    ofSetColor(255, 255, 0);
    // Draw the image from the center of the  mouse
    image1.draw(mx - image1.getWidth() / 2, my - image1.getHeight());

    // Set the image tint to white.
    ofSetColor(255);

    // Draw gradient images with random x position, y position and size.
    for (int i = 0; i < 50; i++)
    {
        float hue = ofRandom(0, 255);
        ofSetColor(ofColor::fromHsb(hue, 255, 255));

        float x = ofRandom(0, w);
        float y = ofRandom(0, h);

        float size = ofRandom(10, 100);

        // Draw the image from the center.
        image0.draw(x - image0.getWidth() / 2, y - image0.getHeight() / 2, size, size);
    }
}

