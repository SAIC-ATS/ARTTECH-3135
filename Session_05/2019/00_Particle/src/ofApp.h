#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

//    glm::vec2 position2d;
//    float x;
//    float y;
//    float z;

    float ballRadius = 40;
    
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;

};

