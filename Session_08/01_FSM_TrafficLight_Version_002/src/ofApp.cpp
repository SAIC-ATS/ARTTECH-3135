#include "ofApp.h"


void ofApp::setup()
{
    // Nothing to setup for now.
}


void ofApp::update()
{
    checkState();
}


void ofApp::draw()
{
    drawState();
}


void ofApp::updateState()
{
    uint64_t now = ofGetElapsedTimeMillis();
    
    if (now > nextTransitionTime)
    {
        // Do the transition!
        
        // What state are we in?
        // We couldn't dop this with if else if statements, but we use a switch.
        switch (currentState)
        {
            case STATE_RED:
                // Do the red stuff here.
                // Transition to the GREEN state.
                currentState = STATE_GREEN;
                // Reset our timer for the GREEN state.
                nextTransitionTime = now + 3000;
                break;
            case STATE_YELLOW:
                // Do the yellow stuff here.
                currentState = STATE_RED;
                nextTransitionTime = now + 2000;
                break;
            case STATE_GREEN:
                // Do the green stuff here.
                currentState = STATE_YELLOW;
                nextTransitionTime = now + 1000;
                break;
            // default:
                // Do something here if you didn't list the case above.
                // This doesn't apply to us because we listed all of our
                // cases above.
        }
    }
    else
    {
        // Do nothing, because it is not time yet.
    }
}

void ofApp::drawState()
{
    // Outside of the traffic light.
    ofFill();
    ofSetColor(ofColor::black);
    ofDrawRectangle(10, 10, 50, 150);
    
    // Draw the outlines for the lights.
    ofNoFill();
    ofSetColor(ofColor::white);
    ofDrawCircle(35, 35, 20);
    ofDrawCircle(35, 85, 20);
    ofDrawCircle(35, 135, 20);
    
    // Draw the filled light.
    ofFill();
    switch (currentState)
    {
        case STATE_RED:
            ofSetColor(ofColor::red);
            ofDrawCircle(35, 35, 20);
            break;
        case STATE_YELLOW:
            ofSetColor(ofColor::yellow);
            ofDrawCircle(35, 85, 20);
            break;
        case STATE_GREEN:
            ofSetColor(ofColor::green);
            ofDrawCircle(35, 135, 20);
            break;
    }
    
}
