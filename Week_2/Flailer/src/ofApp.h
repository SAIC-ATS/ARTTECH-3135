#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;

    void drawGrid(float width, float height, float size = 25);

    bool showGrid = true;

    ofImage femurBone;

    std::vector<ofImage> images;
    std::vector<float> angles;
    std::vector<float> anglesMinimum;
    std::vector<float> anglesMaximum;
    std::vector<float> anglesNoiseIncrement;
    std::vector<float> anglesNoiseOffsets;
    std::vector<float> anglesNoiseScales;
    std::vector<bool> isNewSegment;

};
