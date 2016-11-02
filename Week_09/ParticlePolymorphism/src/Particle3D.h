#pragma once


#include "ofMain.h"
#include "Particle.h"


class Particle3D: public Particle
{
public:
    Particle3D();
    virtual ~Particle3D();

    virtual void update() override;

    virtual void draw() override;

    ofVec3f angle;
    ofVec3f angularVelocity;

};
