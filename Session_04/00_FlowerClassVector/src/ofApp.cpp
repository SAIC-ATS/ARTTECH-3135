#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    ofSetCircleResolution(64);
    
//    flowers = { Flower(), Flower(), Flower() };
    
}


void ofApp::update()
{
    for (std::size_t i = 0; i < flowers.size(); i++)
    {
        flowers[i].update();
    }
}


void ofApp::draw()
{
    for (std::size_t i = 0; i < flowers.size(); i++)
    {
        flowers[i].draw();
    }
}


void ofApp::mousePressed(int x, int y, int button)
{
    Flower aFlower;
    
    aFlower.x = x;
    aFlower.y = y;
    
    flowers.push_back(aFlower);
}
