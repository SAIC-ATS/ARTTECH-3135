//
//  house.hpp
//  houseClassSystem
//
//  Created by Suzanne D Kosek on 11/13/17.
//
//

#pragma once
#include "ofMain.h"


class House{
    
public:
    
    House();
    ~House();
    
    void setup();
    void update();
    void draw();
    
    ofColor roof; //check
    ofColor door; //check
    ofColor dWay;
    ofColor window; //check
    ofColor house; //check
    ofColor chimney; //check
    ofColor smoke;
    
    //house
    float houseX;
    float houseY;
    float houseW;
    float houseH;
    
    //roof
    float roofAX;
    float roofAY;
    float roofBX;
    float roofBY;
    float roofCX;
    float roofCY;
    
    //doorway
    float dWayX;
    float dWayY;
    float dWayH;
    float dWayW;
    
    //door
    float doorX;
    float doorY;
    float doorW;
    float doorH;
    
    //window
    float windowX;
    float windowY;
    float windowW;
    float windowH;
    
    //chimney
    float chimneyX;
    float chimneyY;
    float chimneyW;
    float chimneyH;
    
    //smoke
    float smokeBottomX;
    float smokeBottomY;
    float smokeBottomRad;
    
    float smokeMiddleX;
    float smokeMiddleY;
    float smokeMiddleRad;
    
    float smokeTopX;
    float smokeTopY;
    float smokeTopRad;
    
    float noiseOffSet;
    
    
    
};