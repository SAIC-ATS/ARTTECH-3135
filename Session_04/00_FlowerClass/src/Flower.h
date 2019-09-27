#pragma once


#include "ofMain.h"


class Flower
{
public:
    Flower(); // Default constructor.
    
    
    void draw() const;
    
    ofColor petalColor = ofColor::yellow;
    ofColor centerColor = ofColor::black;
    int numberOfPetals = 4;
    float petalLength = 100;
    float petalWidth = 20;
    float centerRadius = 20;
    
};

