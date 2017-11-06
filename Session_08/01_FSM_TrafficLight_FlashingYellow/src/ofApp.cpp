#include "ofApp.h"


void ofApp::update()
{
    // Get the current time.
    uint64_t now = ofGetElapsedTimeMillis();

    // How much time has passed since the last transition.
    uint64_t dt = now - lastTransitionTime;

    if (currentState == STATE_RED)
    {
        if (dt > 3000)
        {
            currentState = STATE_GREEN;
            lastTransitionTime = now;
        }
    }
    else if (currentState == STATE_YELLOW)
    {
        if (dt > 1000)
        {
            currentState = STATE_FLASHING_YELLOW;
            lastTransitionTime = now;
        }
    }
    else if (currentState == STATE_GREEN)
    {
        if (dt > 6000)
        {
            currentState = STATE_YELLOW;
            lastTransitionTime = now;
        }
    }
    else if (currentState == STATE_FLASHING_YELLOW)
    {
        if (dt > 3000)
        {
            currentState = STATE_RED;
            lastTransitionTime = now;
        }
    }
}


void ofApp::draw()
{
    switch (currentState)
    {
        case STATE_RED:
            // this code happens if the currentState is STATE_RED
            ofSetColor(ofColor::red);
            ofFill();
            ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 3, 40);

            ofSetColor(ofColor::yellow);
            ofNoFill();
            ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 40);

            ofSetColor(ofColor::green);
            ofNoFill();
            ofDrawCircle(ofGetWidth() / 2, 2 * ofGetHeight() / 3, 40);
            break;
        case STATE_YELLOW:
            // this code happens if the currentState is STATE_YELLOW
            ofSetColor(ofColor::red);
            ofNoFill();
            ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 3, 40);

            ofSetColor(ofColor::yellow);
            ofFill();
            ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 40);

            ofSetColor(ofColor::green);
            ofNoFill();
            ofDrawCircle(ofGetWidth() / 2, 2 * ofGetHeight() / 3, 40);
            break;
        case STATE_GREEN:
            // this code happens if the currentState is STATE_GREEN
            ofSetColor(ofColor::red);
            ofNoFill();
            ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 3, 40);

            ofSetColor(ofColor::yellow);
            ofNoFill();
            ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 40);

            ofSetColor(ofColor::green);
            ofFill();
            ofDrawCircle(ofGetWidth() / 2, 2 * ofGetHeight() / 3, 40);
            break;
        case STATE_FLASHING_YELLOW:
            // this code happens if the currentState is STATE_GREEN
            ofSetColor(ofColor::red);
            ofNoFill();
            ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 3, 40);

            // The number of seconds since we started.
            // 0.00001, 0.100002, 0.20002, 0.300099, ....
            float alwaysGoingUp = ofGetElapsedTimef();

            // The goes up and down from -1 to 1 depending on the angle.
            float scaleForTheAlwaysGoingUpAndDownNumber = 10;

            float goesUpAndDownValue = sin(alwaysGoingUp * scaleForTheAlwaysGoingUpAndDownNumber);

            float alpha = ofMap(goesUpAndDownValue, -1, 1, 0, 255);


            ofSetColor(ofColor::yellow, alpha);
            ofFill();
            ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 40);

            ofSetColor(ofColor::green);
            ofNoFill();
            ofDrawCircle(ofGetWidth() / 2, 2 * ofGetHeight() / 3, 40);
            break;
    }
}

