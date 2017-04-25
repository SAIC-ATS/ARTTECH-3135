#pragma once

#include "ofMain.h"

class Particle
{
public:
    void setup();
    void update();
    void draw();

    ofVec3f previousPosition;

    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    float drag = 0.98;
    uint64_t age = 0;

    ofVec3f rotation;

};
