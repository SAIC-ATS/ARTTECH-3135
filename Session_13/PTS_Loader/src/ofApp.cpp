#include "ofApp.h"


void ofApp::setup()
{
    ofEnableDepthTest();
    
    ofBackground(ofColor::black);
    
    mesh = PTSLoader::load("medium.pts");

    std::cout << mesh.getVertices().size() << std::endl;
    
    
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofSetColor(255);
    cam.begin();
    mesh.draw();
    cam.end();
}



