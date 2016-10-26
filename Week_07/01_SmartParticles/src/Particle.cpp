#include "Particle.h"


void Particle::setup()
{
}


void Particle::update()
{
    previousPosition = position;

    velocity += acceleration;
    velocity *= drag;
    position += velocity;

    age++;
}


void Particle::draw()
{
//    ofDrawEllipse(position, 2, 2);

    ofDrawLine(previousPosition, position);
}
