#include "Particle.h"


void Particle::update()
{
    // We don't update the accelerations for now.
    // ax =
    // ay =
    // az =

    // Update the velocity based on the acceleration.
    vx = vx + ax;
    vy = vy + ay;
    vz = vz + az;

    // Update the position based on the velocity.
    x = x + vx;
    y = y + vy;
    z = z + vz;

}


void Particle::draw()
{
    ofDrawCircle(x, y, z, radius);
}
