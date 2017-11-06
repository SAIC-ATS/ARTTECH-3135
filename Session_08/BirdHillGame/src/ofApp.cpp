#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::update()
{
    updateState();
}

void ofApp::draw()
{
    drawState();
}


void ofApp::updateState()
{
    if (currentState == STATE_START)
    {
        yPosition = ofGetHeight() - 30;
        
        if (ofGetKeyPressed(' '))
        {
            currentState = STATE_PLAYING;
        }
    }
    else if (currentState == STATE_PLAYING)
    {
        if (yPosition > ofGetHeight() || yPosition < 0)
        {
            currentState = STATE_END;
        }

        yPosition = yPosition + 1;
    }
    else if (currentState == STATE_END)
    {
        if (ofGetKeyPressed(OF_KEY_RETURN))
        {
            currentState = STATE_START;
        }
    }
}

void ofApp::drawState()
{
    if (currentState == STATE_START)
    {
        ofDrawBitmapString("Press Spacebar to Start", 14, 14);
    }
    else if (currentState == STATE_PLAYING)
    {
        ofDrawBitmapString("Press Spacebar As Fast As Possible To Win", 14, 14);
    }
    else if (currentState == STATE_END)
    {
        if (yPosition > ofGetHeight())
        {
            ofDrawBitmapString("Sorry, you lose. Press Retart To Restart.", 14, 14);
        }
        else
        {
            ofDrawBitmapString("You win! Press Return To Restart.", 14, 14);
        }
    }
    
    ofDrawCircle(ofGetWidth() / 2, yPosition, 30);
}


void ofApp::keyPressed(int key)
{
    if (key == ' ' && currentState == STATE_PLAYING)
    {
        yPosition -= 20;
    }
}
