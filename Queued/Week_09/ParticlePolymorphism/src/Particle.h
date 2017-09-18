#pragma once

#include "ofMain.h"

class Particle
{
public:
    /// \brief Construct a default Particle.
    Particle();

    /// \brief Destroy the particle.
    virtual ~Particle();

    virtual void update();
    virtual void draw();

    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;

    float drag = 0.99;

    uint64_t age = 0;

};
