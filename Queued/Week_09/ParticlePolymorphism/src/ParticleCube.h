#pragma once


#include "ofMain.h"
#include "Particle3D.h"


class ParticleCube: public Particle3D
{
public:
    ParticleCube();
    virtual ~ParticleCube();

    virtual void draw() override;

};
