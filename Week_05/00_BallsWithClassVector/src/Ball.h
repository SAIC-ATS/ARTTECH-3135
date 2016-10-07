#pragma once


#include "ofMain.h"

// TODO:
// What is operator overloading
// Naming conventions
// ... dot-accessors.x

class Ball
{
public:
    void update();
    void draw();

    float width = 20;
    float height = 20;

    // x, y, z position.
    ofVec3f position;

    // x, y z velocity.
    ofVec3f velocity;

    ofVec3f acceleration;

    float drag = 0.98;

};
