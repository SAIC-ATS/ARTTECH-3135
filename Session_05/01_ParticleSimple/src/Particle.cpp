#include "Particle.h"


Particle::Particle()
{
}


Particle::~Particle()
{
}


void Particle::update()
{
    velocity = velocity + acceleration;
    position = position + velocity;
}


void Particle::draw()
{
    ofFill();
    ofSetColor(color);
    ofDrawCircle(position, radius);
}
