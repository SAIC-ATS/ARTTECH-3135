#include "Particle.h"



Particle::Particle()
{
}


Particle::~Particle()
{
}


void Particle::update()
{
    velocity += acceleration;
    // velocity = velocity + acceleration;

    velocity *= drag;
    // velocity = velocity * drag;

    position += velocity;
    // position = position + velocity;
    
    age++;
}


void Particle::draw()
{
    ofDrawEllipse(position, 10, 10);
}
