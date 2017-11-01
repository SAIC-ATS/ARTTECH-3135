#include "Particle.h"


Particle::Particle()
{
}

Particle::Particle(float mass, glm::vec3 pos)
{
    this->mass = mass;
    this->pos = pos;
    this->speed = *new glm::vec3(0, 0, 0);
}


Particle::~Particle()
{
}


void Particle::update()
{
    this->speed *= 0.98;
    this->pos += speed;
    
    angularVelocity = angularVelocity + angularAcceleration;
    orientation = orientation + angularVelocity;
}


void Particle::draw()
{
    ofFill();
    ofSetColor(color);
        
    ofPushMatrix();
    
        ofTranslate(pos);
        ofRotateXDeg(orientation.x);
        ofRotateYDeg(orientation.y);
        ofRotateZDeg(orientation.z);
        myTex.draw(-myTex.getWidth() / 2, -myTex.getHeight() / 2);
    
    ofPopMatrix();
}

void Particle::attract(Particle mouseParticle)
{
    float dist = ofClamp((float)glm::distance(pos, mouseParticle.pos), 10, 100);
    glm::vec3 force = (mouseParticle.pos - pos) * mouseParticle.mass * mass * g / (dist * dist);
    glm::vec3 accel = force/(mass*100);
    this->speed += accel;
}
