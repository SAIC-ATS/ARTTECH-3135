#pragma once

#include "ofMain.h"

class Particle
{
public:
    Particle();
    Particle(float mass, glm::vec3 pos);
    ~Particle();

    void update();
    void draw();
    void attract(Particle b);

    float radius = 0.0;
    float mass;
    float g = 0.1;
    ofColor color;
    
    ofTexture myTex;
    
    glm::vec3 orientation;
    glm::vec3 angularVelocity;
    glm::vec3 angularAcceleration;
    glm::vec3 pos;
    glm::vec3 speed;

};
