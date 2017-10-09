#include "ofApp.h"


void ofApp::setup()
{
    cartwheeler.load("dude.png");
}


void ofApp::update()
{
    yPosition = ofGetHeight() / 2;

    xPosition = ofMap(angleDeg, 0, 360, 0, cartwheeler.getWidth() + cartwheeler.getHeight());

    if (xPosition > ofGetWidth())
    {
        angleDeg = 0;
    }
    else
    {
        float wrappedAngle = ofWrap(angleDeg, 0, 360);
//        angleDegIncrement = ofMap(wrappedAngle, 0.1, 360, 0, 5);

        angleDegIncrement = 0.1 + angleDegIncrement * angleDegIncrement;

        angleDeg += angleDegIncrement;
    }
}


void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(xPosition, yPosition);
    ofRotateZDeg(angleDeg);
    cartwheeler.draw(-cartwheeler.getWidth() / 2, -cartwheeler.getHeight() / 2);
    ofPopMatrix();

}


void ofApp::keyPressed(int key)
{
}
