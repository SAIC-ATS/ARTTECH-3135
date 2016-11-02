#include "Particle3D.h"



Particle3D::Particle3D()
{
}


Particle3D::~Particle3D()
{
}


void Particle3D::update()
{
    // call the base class to make sure the position, velocity,
    // accceleration, etc get calculated.
    Particle::update();

    // Update the angles with the current angular velocity.
    angle += angularVelocity;
}

void Particle3D::draw()
{
    ofPushMatrix();
    ofTranslate(position); // Move the the position.
    ofRotateX(angle.x); // Rotate along x-axis.
    ofRotateY(angle.y); // Rotate along y-axis.
    ofRotateZ(angle.z); // Rotate along z-axis.
    ofDrawSphere(0, 0, 0, 30);
    ofPopMatrix();
}
