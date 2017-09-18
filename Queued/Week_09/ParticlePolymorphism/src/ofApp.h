#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Particle3D.h"
#include "ParticleCube.h"

class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void addParticle();
    void addParticle3D();
    void addParticleCube();

    void mousePressed(int x, int y, int button);

    std::vector<std::shared_ptr<Particle>> particles;

    ofEasyCam cam;

};
