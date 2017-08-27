#pragma once

#include "ofMain.h"
#include "Particle.h"



class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;

    std::vector<Particle> particles;
    std::vector<ofVec3f> targets;

    float blend = 0;
    bool goingUp = false;

};
