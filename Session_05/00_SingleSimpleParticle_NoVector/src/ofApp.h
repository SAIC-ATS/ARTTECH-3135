#pragma once


#include "ofMain.h"
#include "Particle.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
    
    Particle p;

};
