//
//  snow.hpp
//  project05
//
//  Created by Suzanne D Kosek on 12/10/17.
//
//

#pragma once
#include "ofMain.h"

class snow{
public:
    void setup();
    void update();
    void draw();
    
    // Represent the "Position" feature
    glm::vec3 position;
    
    // Represent the "Velocity" feature
    glm::vec3 velocity;
    
    // Represent the Acceleration feature
    glm::vec3 acceleration;

    uint64_t age = 0;
    
    float radius = 30;
    
    ofColor snowColor;
    
    
};