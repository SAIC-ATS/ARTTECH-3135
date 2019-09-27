#pragma once


#include "ofMain.h"
#include "Flower.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void mousePressed(int x, int y, int button) override;
    
    std::vector<Flower> flowers;
    
};

