#pragma once


#include "ofMain.h"


class Particle
{
public:
    void setup();
    void update();
    void draw();

    // Is my particle dead yet?
    // is age > ageAtDeath
    bool isDead() const;
    
    // Where is our particle?
    glm::vec3 position;
    
    // How quickly the position is changing? (aka what is its velocity)
    glm::vec3 velocity;

    // How quickly is the veclocity changing?
    glm::vec3 acceleration;
    
    // What is size of my particle?
    float size = 10;
    
    // What color is the particle?
    ofColor color;
    
    // How old is the particle?
    float age = 0;
    
    // At what age will this particle "die"?
    float ageAtDeath = 100;
    
    // What texture is drawn?
    ofTexture texture;

};
