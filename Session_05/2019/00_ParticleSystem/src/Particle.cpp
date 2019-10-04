#include "Particle.h"



void Particle::setup()
{
    position.x = ofRandomWidth();
    position.y = ofRandomHeight();
    
    color = ofColor::fromHsb(ofRandom(255), 255, 255);
    
    size = ofRandom(10, 40);
    
    ageAtDeath = ofRandom(50, 250);
    
    acceleration.y = 0.25;
}


void Particle::update()
{
    age++;
    
    velocity += acceleration;
    position += velocity;
}


void Particle::draw()
{
    ofFill();
    
    float alpha = ofMap(age, 0, ageAtDeath, 255, 0, true);
    
    ofSetColor(color, alpha);

    texture.draw(position, size, size);
}


bool Particle::isDead() const
{
    return age > ageAtDeath;
}
