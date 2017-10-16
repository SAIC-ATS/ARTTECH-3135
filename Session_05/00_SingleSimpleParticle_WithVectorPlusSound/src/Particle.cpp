#include "Particle.h"


void Particle::update()
{
    // Update the velocity based on the acceleration.
    velocity += acceleration;

    // Update the position based on the velocity.
    position += velocity;

}


void Particle::draw()
{
    ofDrawCircle(position, radius);
}
