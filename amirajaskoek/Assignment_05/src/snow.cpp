//
//  snow.cpp
//  project05
//
//  Created by Suzanne D Kosek on 12/10/17.
//
//

#include "snow.h"

void snow::setup(){
    

    
}

void snow::update(){
    
    
    
    // Update the velocity based on the acceleration.
    velocity += acceleration;
    
    // Update the position based on the velocity.
    position += velocity;
    
    age++;
    
}

void snow::draw(){
    
    
     ofSetColor(snowColor);
     ofDrawCircle(position, radius);
    
    
    
}