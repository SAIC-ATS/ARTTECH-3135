#include "ofApp.h"


void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);

    int numRows = 5;

    for (int x = 0; x <= ofGetWidth(); x++)
    {
        for (int row = 0; row <= numRows; row++)
        {
            if (x % (ofGetWidth() / (row + 2)) == 0)
            {
                int yStart = ofGetHeight() / numRows * (row);
                int yEnd   = ofGetHeight() / numRows * (row + 1);
                ofDrawLine(x, yStart, x, yEnd);

                if (x == 0)
                {
                    ofDrawLine(0, yEnd, ofGetWidth(), yEnd);
                }
            }
        }
    }
}













