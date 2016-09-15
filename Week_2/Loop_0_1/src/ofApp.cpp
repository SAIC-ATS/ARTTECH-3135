#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);

    int width = ofGetWidth();
    int numRows = 5;
    int rowMultiplier = 100;
    int rowHeight = ofGetHeight() / numRows;

    for (int x = 0; x <= width; x++)
    {
        for (int row = 0; row <= numRows; row++)
        {
            int numSectionsPerRow = width / (row + 2.f);

            if (x % numSectionsPerRow == 0)
            {
                int yStart = rowHeight * (row);
                int yEnd   = rowHeight * (row + 1);
                ofDrawLine(x, yStart, x, yEnd);

                if (x == 0)
                {
                    ofDrawLine(0, yEnd, width, yEnd);
                }
            }
        }
    }
}













