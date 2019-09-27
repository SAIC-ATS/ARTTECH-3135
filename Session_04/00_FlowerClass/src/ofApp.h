#pragma once


#include "ofMain.h"
#include "Flower.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    Flower myFlower;
    Flower myOtherFlower;
    Flower myOtherFlowerAgain;

    int i = 0;
    int j = 1;
    
};

