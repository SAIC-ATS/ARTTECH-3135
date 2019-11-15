#pragma once


#include "ofMain.h"
#include "PTSLoader.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofMesh mesh;
    
    ofEasyCam cam;
    
};
