#pragma once

#include "ofMain.h"

class Particle
{
public:
    Particle();
    ~Particle();

    void update();
    void draw();

    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;

    float radius = 0.0;
    ofColor color;

    // 2) Challenge: Add an angle and an angleIncrement
    // and draw rotating ... something.

    

};
