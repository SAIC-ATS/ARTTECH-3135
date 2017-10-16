#include "Particle.h"


Particle::Particle()
{
}


Particle::~Particle()
{
}


void Particle::update()
{
    angularVelocity = angularVelocity + angularAcceleration;
    orientation = orientation + angularVelocity;

    velocity = velocity + acceleration;
    position = position + velocity;
}


void Particle::draw()
{
    ofFill();
    ofSetColor(color);

    ofPushMatrix();
    ofTranslate(position);
    ofRotateXDeg(orientation.x);
    ofRotateYDeg(orientation.y);
    ofRotateZDeg(orientation.z);

//    ofDrawAxis(radius);
    ofDrawBox(radius);

//    ofDrawCircle(position, radius);


    ofPopMatrix();
}
