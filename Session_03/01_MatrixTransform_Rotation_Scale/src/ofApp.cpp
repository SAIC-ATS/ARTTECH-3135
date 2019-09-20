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
    ofSetColor(ofColor::black);
    drawGrid();

    ofPushMatrix();
    
    ofTranslate(100, 100);

    ofSetColor(ofColor::blue);
    drawGrid();
    
    ofRotateZDeg(45);
    ofSetColor(ofColor::green);
    drawGrid();
    
    ofScale(2.0, 0.5, 1.0); // x, y, z axes
    ofSetColor(ofColor::red);
    drawGrid();


    ofPopMatrix();
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
