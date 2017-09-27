#pragma once


#include "ofMain.h"
#include "Face.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    Face myFace;

};
