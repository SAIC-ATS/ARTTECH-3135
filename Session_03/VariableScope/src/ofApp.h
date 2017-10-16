#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    void keyPressed(int key) override;

    int myA; // This variable has "class" scope.
    int myC = 0; // This variable has "class" scope.

    int myVariable = 99; // This variable has "class" scope.

};
