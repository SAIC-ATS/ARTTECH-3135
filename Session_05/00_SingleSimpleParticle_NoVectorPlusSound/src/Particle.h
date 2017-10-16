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
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;

    // Represent the "Velocity" feature
    float vx = 0.0;
    float vy = 0.0;
    float vz = 0.0;

    // Represent the Acceleration feature
    float ax = 0.0;
    float ay = 0.0;
    float az = 0.0;

    float radius = 30;

};
