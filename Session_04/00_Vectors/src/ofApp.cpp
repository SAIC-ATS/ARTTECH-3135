#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    
//    std::vector<float> xPositions;

// load json or xml from the hard disk ...
    
//    xPositions;
//    xPositions.push_back(66);
//    xPositions.push_back(357);

}


void ofApp::update()
{
}


void ofApp::draw()
{
    for (std::size_t i = 0; i < xPositions.size(); i++)
    {
        float xAtIPosition = xPositions[i];
        ofDrawCircle(xAtIPosition, ofGetHeight() / 2, 50);
    }
    
}


void ofApp::exit()
{
    // Write some code that would save xPositions ... to json ....
}


void ofApp::mousePressed(int x, int y, int button)
{
    xPositions.push_back(x);
    
    std::cout << ofToString(xPositions) << std::endl;
    
}
