#pragma once


#include "ofMain.h"
#include "Face.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    std::vector<Face> myFaces;

};
