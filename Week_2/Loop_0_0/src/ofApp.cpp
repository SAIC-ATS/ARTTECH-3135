#include "ofApp.h"


void ofApp::setup()
{
}

void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);

    for (int x = 0; x <= 500; x++)
    {
        if (x % (500 / 2) == 0)
        {
            int yStart = 0 * 500 / 5;
            int yEnd = yStart + 500 / 5;
            ofDrawLine(x, yStart, x, yEnd);
        }

        if (x % (500 / 3) == 0)
        {
            int yStart = 1 * 500 / 5;
            int yEnd = yStart + 500 / 5;
            ofDrawLine(x, yStart, x, yEnd);
        }

        if (x % (500 / 4) == 0)
        {
            int yStart = 2 * 500 / 5;
            int yEnd = yStart + 500 / 5;
            ofDrawLine(x, yStart, x, yEnd);
        }

        if (x % (500 / 5) == 0)
        {
            int yStart = 3 * 500 / 5;
            int yEnd = yStart + 500 / 5;
            ofDrawLine(x, yStart, x, yEnd);
        }

        if (x % (500 / 6) == 0)
        {
            int yStart = 4 * 500 / 5;
            int yEnd = yStart + 500 / 5;
            ofDrawLine(x, yStart, x, yEnd);
        }
    }

    for (int y = 0; y <= 500; y += (500 / 5))
    {
        if (y % (500 / 5) == 0)
        {
            ofDrawLine(0, y, 500, y);
        }
    }
}













