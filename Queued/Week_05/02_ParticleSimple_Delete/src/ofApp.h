#pragma once

#include "ofMain.h"
#include "Particle.h"


class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void mousePressed(int x, int y, int button);


    std::vector<Particle> particles;

    ofImage smoke;

};
