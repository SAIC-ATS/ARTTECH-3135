#pragma once


#include "ofMain.h"


class Flower
{
public:
    Flower(); // Default constructor.
    
    void update();
    void draw() const;
    
    ofColor petalColor = ofColor::yellow;
    ofColor centerColor = ofColor::black;
    int numberOfPetals = 4;
    float petalLength = 100;
    float petalWidth = 20;
    float centerRadius = 20;
    
    float noiseAmplitudeDeg = 10;
    float noiseOffset = 0;
    float noiseStep = 0.1;
    
    float x = 0;
    float y = 0;
    
};

