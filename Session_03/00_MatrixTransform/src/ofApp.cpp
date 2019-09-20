#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::update()
{
}


void ofApp::draw()
{
    // Create a new frame of reference that builds on the previous.
    ofPushMatrix(); // A ofPushMatrix() should always be paired a ofPopMatrix().
    
        ofTranslate(ofGetMouseX(), ofGetMouseY()); // Move (translate) the entire drawing surface to x = 100, y = 100

        ofSetColor(100);
        drawGrid(); // Frame of reference.

        ofSetColor(ofColor::red);
        ofDrawRectangle(0, 0, 100, 100);

        ofSetColor(ofColor::green);
        ofDrawRectangle(50, 50, 100, 100);

        ofTranslate(25, 25);
        ofSetColor(ofColor::pink);
        ofDrawRectangle(0, 0, 50, 50);


    ofPopMatrix(); // Exit out of the current frame of reference and return to the previous.

    ofSetColor(ofColor::yellow);
    ofDrawRectangle(0, 0, 50, 50);
    
}


void ofApp::drawGrid()
{
    int gridStep = 20;
    int numRows = 10;
    int numCols = 10;
    
    // Draws the column lines.
    for (int x = 0; x < numCols + 1; x++)
    {
        ofDrawLine(x * gridStep,        // x-start
                   0,                   // y-start
                   x * gridStep,        // x-end
                   numRows * gridStep); // y-end
    }
    
    // Draws the rows lines.
    for (int y = 0; y < numRows + 1; y++)
    {
        ofDrawLine(0,                   // x-start
                   y * gridStep,        // y-start
                   numCols * gridStep,  // x-end
                   y * gridStep);       // y-end
    }
}



void ofApp::keyPressed(int key)
{
}


void ofApp::keyReleased(int key)
{
}



void ofApp::mouseMoved(int x, int y)
{
}


void ofApp::mouseDragged(int x, int y, int button)
{
}


void ofApp::mousePressed(int x, int y, int button)
{
}


void ofApp::mouseReleased(int x, int y, int button)
{
}


void ofApp::mouseEntered(int x, int y)
{
}


void ofApp::mouseExited(int x, int y)
{
}


void ofApp::windowResized(int w, int h)
{
}


void ofApp::gotMessage(ofMessage msg)
{
}


void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
