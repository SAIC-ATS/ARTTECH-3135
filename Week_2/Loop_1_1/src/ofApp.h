#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void drawGrid();

    float x = 0;
    float y = 0;
    float offsetX = 0;
    float offsetY = 0;
    float angle = 0;
    float radius = 200;

    float angleIncrementDegrees = 1;
};
