#pragma once


#include "ofMain.h"
#include "Particle.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    std::vector<Particle> particles;

    glm::vec3 boundingSize;

    ofEasyCam cam;

};
