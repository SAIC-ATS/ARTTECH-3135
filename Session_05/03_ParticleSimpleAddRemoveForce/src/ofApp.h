#pragma once


#include "ofMain.h"
#include "Particle.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void mousePressed(int x, int y, int button) override;

    void makeNewParticle(float x, float y);

    std::vector<Particle> particles;

};
