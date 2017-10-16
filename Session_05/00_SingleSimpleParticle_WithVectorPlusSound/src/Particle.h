#pragma once


#include "ofMain.h"


class Particle
{
public:
    // Update the position, velocity and accleration.
    void update();

    // Will render the particle on the screen.
    void draw();

    // Represent the "Position" feature
    glm::vec3 position;

    // Represent the "Velocity" feature
    glm::vec3 velocity;

    // Represent the Acceleration feature
    glm::vec3 acceleration;

    // The age of our particle in number of frames.
    uint64_t age = 0;

    float radius = 30;

};
